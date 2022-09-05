# Imports
from Lexical_Analyzer.Modules import dfa

line = 1 # Store which line of the source program the parser is on
column = 1 # Store at what position in the source program line the parser is
route = [] # Store the last traveled path


'''
@return a string with information regarding the error inside the source program
'''
def analyze_error():

    global line
    global column
    global route

    if (route[-1] == -1):
        ind = dfa.index.get(route[-2])
        column = column + (len(route) - 2)

    else:
        ind = dfa.index.get(route[-1])
        column = column + (len(route) - 1)
        
    expected = '' # Will store the characters that were expected

    for i in dfa.dfa_table[ind]:
        expected = expected + ' ' + i
    
    info = 'ERRO:\n\n' + f'Linha: {line}\n' + f'Coluna: {column}\n' + 'Era esperado algum dos seguintes caracteres: ' + expected
    return info