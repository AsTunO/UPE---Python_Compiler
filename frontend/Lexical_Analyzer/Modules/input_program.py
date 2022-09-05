# imports
from Lexical_Analyzer.Modules import error

source_program = ""
length = 0
lexeme_begin = 0
index = 0 # Stores the index of the character that will be taken in the next call to next_char()


'''
@return the next character from the source program or the empty string if the program has reached the end
'''
def next_char():

    global source_program
    global length
    global index

    if (index < length):
        error.column = error.column + 1 # Increments the value of the column variable of the error module that stores in which column of the source program line we are
        index = index + 1
        return source_program[index - 1]
    
    else:
        return '' 


'''
@return the reading of the lexeme in one character
'''
def go_back():
    
    global index

    error.column = error.column - 1 
    index = index - 1


'''
@return a slice of source_program containing the characters that have been read since the start of reading a new lexeme
'''
def get_lexeme():
    
    global source_program
    global lexeme_begin
    global index

    lexeme = source_program[ lexeme_begin : index ] # Pass slice to lexeme
    lexeme_begin = index

    return lexeme


'''
@param absolute_path: The path of archive
@return the state of the funcion
'''
def receive_program(absolute_path: str):
    
    global source_program
    global length
    global path

    try:
        program = open(absolute_path, mode='r', encoding='utf-8')
        
    except FileNotFoundError:
        return 0
    
    source_program = program.read()
    program.close()
    length = len(source_program)

    return 1
