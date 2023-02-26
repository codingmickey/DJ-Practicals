def encrypt(message, shift):
    ciphertext = ''
    for char in message:
        # Check if the character is an uppercase or lowercase letter
        if char.isupper():
            ciphertext += chr((ord(char) + shift - 65) % 26 + 65)
        elif char.islower():
            ciphertext += chr((ord(char) + shift - 97) % 26 + 97)
        else:
            ciphertext += char
    return ciphertext

def decrypt(ciphertext, shift):
    message = ''
    for char in ciphertext:
        # Check if the character is an uppercase or lowercase letter
        if char.isupper():
            message += chr((ord(char) - shift - 65) % 26 + 65)
        elif char.islower():
            message += chr((ord(char) - shift - 97) % 26 + 97)
        else:
            message += char
    return message

def brute_force_attack(ciphertext):
    for shift in range(1, 26):
        message = decrypt(ciphertext, shift)
        print(f'Shift = {shift:2d}: {message}')


# Example usage
message = 'This is a secret message'
shift = 3

ciphertext = encrypt(message, shift)
print(ciphertext) # Output: Wklv lv d vhfuhw phvvdjh.

decrypted_message = decrypt(ciphertext, shift)
print(decrypted_message) # Output: This is a secret message.

brute_force_attack(ciphertext)