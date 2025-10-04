import requests
import sys

if len(sys.argv) == 1:
    sys.exit("Missing command-line argument")
elif len(sys.argv) > 2:
    sys.exit("Too many arguments")
else:
    try:
        n = float(sys.argv[1])
    except ValueError:
        sys.exit("Command-line argument is not a number")

try:
    response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
    o = response.json()
    price_str = o["bpi"]["USD"]["rate"]
    price = float(price_str.replace(",", ""))
    price *= n


    print(f"${price:,.4f}")
except requests.RequestException:
    sys.exit("An error occured while accessing the API")
except KeyError:
    sys.exit("Unexpected data format in API response")

