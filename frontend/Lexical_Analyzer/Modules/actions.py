# Imports
from Lexical_Analyzer.Modules import input_program, output_tokens, error
from Symbols_Table.identifiers import search_id_table

tags = {
    '&&': 256,
    'int': 257,
    'float': 257,
    'bool': 257,
    'char': 257,
    'break': 258,
    'do': 259,
    'else': 260,
    '==': 261,
    'false': 262,
    '>=': 263,
    'id': 264,
    'if': 265,
    '<=': 267,
    '!=': 269,
    'num': 270,
    '||': 271,
    'real': 272,
    'true': 274,
    'while': 275  
}

accepting_states = (1, 2, 4, 5, 6, 9, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 23, 29, 30, 31, 33, 38)
keywords = ("if", "else", "while", "do", "break", "true", "false")
types = ("int", "char", "float", "bool") # The reserved words that match the basic token

# Acceptance state groups with similar actions
group1 = (4, 5, 6, 9, 11, 12, 14, 15, 16, 17, 18, 19, 20) # Tokens without attribute value
group2 = {29: 'equal', 33: 'relop'} # Attribute-valued tokens
group3 = {2: 'num', 38: 'real'} # For tokens num is real


'''
@param state
@return the state of the function
'''
def action(state: int):
    
    global accepting_states
    global group1
    global group2
    global group3
    global keywords
    global types

    lexeme = input_program.get_lexeme()
    tag = tags.get(lexeme)
    token = {'tag': tag, 'lexeme': lexeme}

    if (state == 1): # Id
        if (lexeme in types):
            if (lexeme == 'int'):
                width = 4
            elif (lexeme == 'float'):
                width = 8
            elif (lexeme == 'char' or lexeme == 'bool'):
                width = 1
            token = {'tag': tag, 'lexeme': lexeme, 'width': width}
        elif not (lexeme in keywords):
            tag = tags["id"]
            token = {'tag': tag, 'lexeme': lexeme}
            search_id_table(lexeme)
        
    elif (state in group3):
        if ('.' in lexeme):
            tag = tags.get("real")
        else:
            tag = tags.get("num")
        token = {'tag': tag, 'value': eval(lexeme)}

    elif (state in group1):
        token = {'tag': lexeme}

    elif (state == 30 or state == 31):
        token = {'tag': tag, 'lexeme': lexeme}
        
    elif (state == 23): # Newline 
        error.column = 1 # Resets the column variable of the error module which stores in which column of the source program line they are
        length = len(lexeme) 
        error.line = error.line + length # Increments the line variable of the error module that stores in which line of the source program we are according to the amount of newline characters found 
        return True

    elif (state == 21): # Whitespace and tabs
        return True

    output_tokens.store_token(token)
    return True


'''
@param route
@return the state of the router
'''  
def search_route(route: list):

    global accepting_states

    error.route = route
            
    for i in range(len(route) - 1, 0, -1):

        if (route[i] in accepting_states):
            return route[i]

        input_program.go_back()
        
    return -1
