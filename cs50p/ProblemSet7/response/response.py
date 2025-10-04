from validator_collection import checkers

email = input("What's your email address: ").strip().lower()

is_valid = checkers.is_email(email)

if is_valid:
    print("Valid")
else:
    print("Invalid")
