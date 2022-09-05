# Imports
from Lexical_Analyzer.Modules import input_program, error, actions, dfa, output_tokens


'''
@param absolute_path: The path of archive
@return the state of the action
'''
def analyze(absolute_path: str):
    
    status = input_program.receive_program(absolute_path) # The path is sent to the module that handles the input

    if (status == 0): # In case the file open operation is not successful
        return (0, 'Falha ao abrir o programa fonte')

    route_dfa = [0] # variable that will store the path taken in the DFA diagram

    while (True):
        while (route_dfa[-1] != -1): # Check if the last character from the lexeme
            
            charac = input_program.next_char()

            if (charac != ''): # If the program has not reached the end
                route_dfa.append(dfa.next_state(route_dfa[-1], charac)) # Get the next DFA state

            elif (route_dfa[-1] == 0): # If the program has finished and the reading of a new lexeme has not started
                status = output_tokens.put_in_file(absolute_path)

                if (status == 0): # Case of mistake at the creation of the archive 
                    return (0, 'Falha ao criar o arquivo de resultado do analisador léxico!')

                return (1, 'Análise léxica concluída com sucesso!')
                
            else:
                break


        state = actions.search_route(route_dfa) # Looks for an accepting state on the path taken by the DFA
            
        if (state == -1): # If the source program has any errors
            return (0, error.analyze_error())

        actions.action(state) # Performs the action corresponding to the found acceptance state
        
        route_dfa = [0] # Reset the way