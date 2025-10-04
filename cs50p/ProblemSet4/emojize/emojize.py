import emoji

user_input = input("Input: ")


result = emoji.emojize(user_input, language = "alias")
print(f"Output: {result}")

