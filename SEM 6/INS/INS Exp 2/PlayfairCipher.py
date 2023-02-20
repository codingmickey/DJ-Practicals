def make_matrix(key):
    key_square = [[0]*5 for _ in range(5)]

    print(key_square)

    # Remove duplicates from the key
    modified_key = "".join(dict.fromkeys(key))

    row = 0
    col = 0

    print(modified_key)

    # Iterate the key and add to the matrix
    for char in modified_key:
        key_square[row][col] = char
        print(row, col, char, key_square)
        col = col + 1
        if col == 5:
            col = 0
            row = row + 1

    print(row, col, key_square)

    # Add the remaining alphabets
    for alpha in range(65, 91):
        # Ignoring 'J' and checking if the Character is not in the KEY
        if (alpha != 74) and (chr(alpha) not in modified_key):
            key_square[row][col] = chr(alpha)
            col = col + 1
            if col == 5:
                col = 0
                row = row + 1

    print(row, col, key_square)

    return key_square


def find_in_matrix(element, matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j] == element:
                return (i, j)


def encrypt(plain_text, key):

    matrix = make_matrix(key)

    cipher_text = ""

    plain_text = plain_text.replace(" ", "")
    print(plain_text)

    plain_text_pairs = []

    plain_text_modified = ""

    for x in range(len(plain_text) - 1):
        plain_text_modified += plain_text[x]
        if plain_text[x] == plain_text[x+1]:
            plain_text_modified += "X"

    plain_text_modified += plain_text[-1]

    print(plain_text_modified)

    if len(plain_text_modified) % 2:
        plain_text_modified += "X"

    for x in range(0, len(plain_text_modified), 2):
        plain_text_pairs += [[plain_text_modified[x], plain_text_modified[x+1]]]

    print(plain_text_pairs)

    f = [print(_) for _ in matrix]

    print(find_in_matrix('M', matrix))
    print(find_in_matrix('E', matrix))

    cipher_text = ""

    for each_pair in plain_text_pairs:
        (row1, col1) = find_in_matrix(each_pair[0], matrix)
        (row2, col2) = find_in_matrix(each_pair[1], matrix)
        # print([row1, col1, row2, col2])

        if row1 == row2:
            cipher_text += matrix[row1][(col1+1) % 5] + matrix[row1][(col2+1) % 5]
        elif col1 == col2:
            cipher_text += matrix[(row1+1) % 5][col1] + matrix[(row2+1) % 5][col1]
        else:
            cipher_text += matrix[row1][col2] + matrix[row2][col1]

    print("1. PLAIN TEXT: " + plain_text_modified)
    print("1. CIPHER TEXT: " + cipher_text)

    return plain_text_modified, cipher_text


def decrypt(cipher_text, key):
    
    matrix = make_matrix(key)

    cipher_text_pairs = []

    for x in range(0, len(cipher_text), 2):
        cipher_text_pairs += [[cipher_text[x], cipher_text[x+1]]]

    
    plain_text = ""

    for each_pair in cipher_text_pairs:
        (row1, col1) = find_in_matrix(each_pair[0], matrix)
        (row2, col2) = find_in_matrix(each_pair[1], matrix)
        # print([row1, col1, row2, col2])

        if row1 == row2:
            plain_text += matrix[row1][(col1-1) % 5] + matrix[row1][(col2-1) % 5]
        elif col1 == col2:
            plain_text += matrix[(row1-1) % 5][col1] + matrix[(~~row2-1) % 5][col1]
        else:
            plain_text += matrix[row1][col2] + matrix[row2][col1]

    print("2. CIPHER TEXT: " + cipher_text)
    print("2. PLAIN TEXT: " + plain_text)

    return plain_text


plain_text = "Meet me tomorrowX".upper()
print(plain_text)
# plain_text = input("Enter the plain text: ").upper()
key = "balloonf".upper()
# key = input("Enter the key: ").upper()
print(key)


plain_text_modified, cipher_from_function = encrypt(plain_text, key)

plain_text_from_function = decrypt(cipher_from_function, key)

if plain_text_modified == plain_text_from_function:
    print("✅️ Both encryption and decryption are working fine!")
else:
    print("❌️ Something is not correct!!!!")