import random
import string

replacement_dict = {}

for _ in range(5):
    while True:
        char = input("Enter a lowercase character: ").strip()
        if char in string.ascii_lowercase and char not in replacement_dict:
            break
        print("Invalid input or duplicate letter. Please try again.")

    replacement_set = set()
    while len(replacement_set) < 3:
        replacement = input(f"Enter a replacement for '{char}': ").strip()
        if len(replacement) == 1 and replacement not in replacement_set and replacement not in replacement_dict:
            replacement_set.add(replacement)
        else:
            print("Invalid or duplicate replacement. Please try again.")

    replacement_dict[char] = list(replacement_set)

passwords = [''.join(random.choices(string.ascii_lowercase, k=15)) for _ in range(5)]

categorized_passwords = {"Strong": [], "Weak": []}

for password in passwords:
    modified_password = ""
    counter = 0

    for char in password:
        if char in replacement_dict:
            modified_password += random.choice(replacement_dict[char])
            counter += 1
        else:
            modified_password += char

    if counter >= 4:
        categorized_passwords["Strong"].append(modified_password)
    else:
        categorized_passwords["Weak"].append(modified_password)

print("\nGenerated Passwords:")

print("\nStrong Passwords:")
for strong_pwd in categorized_passwords["Strong"]:
    print(strong_pwd)

print("\nWeak Passwords:")
for weak_pwd in categorized_passwords["Weak"]:
    print(weak_pwd)
