# Imports
import os

tokens_found = [] # Store all tokens found while reading the program

'''
@param token
@return the list of the tokens with the new token
'''
def store_token(token: dict):
    
    global tokens_found
    tokens_found.append(token)


'''
@param directory: String with the path that are going to be settled the archive
@return the state of the operation
'''
def put_in_file(directory: str):
    
    global tokens_found

    try:
        file = open(os.path.join( os.path.dirname(directory), 'Tokens.txt'), mode='w', encoding='utf-8' )

    except FileNotFoundError:
        return 0

    for token in tokens_found:
        file.write("Token: " + str(token) + "\n")
  
    file.close()
    return 1