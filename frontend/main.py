# Imports
import sys
from Lexical_Analyzer.analyzer import analyze
from Syntactic_Analyzer.parser import parser

def main():
    print("--------------------------------- Compilador(Frontend) ---------------------------------")
    print('ANALISADOR LÉXICO: ')
    print('\n(Insira o path absoluto do programa fonte)')

    absolute_path = input('>>> ')  # Get the path from the user

    status = analyze(absolute_path)  # Get the status of the analyser from path

    print('\n\n' + status[1]) 

    if(status[0]): # Verify if the Lexical analyze have be done with success
        print('------------------------------------------------------------------------------')
        print('ANALISADOR SINTÁTICO: ')
        syntactic_analyzer_status = parser(absolute_path) # Calls the Syntactic Analyzer
        if(syntactic_analyzer_status):
            print("Análize sintática feita com sucesso")


if __name__ == "__main__":
    if len(sys.argv) > 1:
        status = analyze(sys.argv[1])
        print('\n\n' + status[1]) 
    else:
        main()
        
