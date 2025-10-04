# function to convert the input
def convert(user_input):
    # replacements
    user_input = user_input.replace(":)", "🙂")
    user_input = user_input.replace(":(", "🙁")
    return user_input

def main():
    text = input("Enter the text: ")
    # calling the function and printing the return value
    print(convert(text))

main()

