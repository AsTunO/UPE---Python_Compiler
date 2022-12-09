import os

def parser(directory: str):

    tokens = open(os.path.join( os.path.dirname(directory), 'Tokens.txt'), mode='r', encoding='utf-8')

    print("Tokens Recebidos -> ")
    for token in tokens:
        print(token)

    return 1
