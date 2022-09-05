"""
MODULE TO HANDLE DFA STATE TRANSITIONS
"""

letter =    (
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
            'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'ç', 'á', 'é', 'í',
            'ó', 'ú', 'â', 'ê', 'î', 'ô', 'û', 'ã', 'õ', 'ä', 'ë', 'ï', 'ö', 'ü'           
            )

digit = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')

index = { # Associates each DFA state with the index in the dfa variable that contains the transitions from that state     
        
        0: 0, 1: 1, 2: 2, 4: -1, 5: -1, 6: 3, 7: 4, 8: 5,
        9: -1, 11: 6, 12: 7, 14: -1, 15: -1, 16: -1,
        17: -1, 18: -1, 19: -1, 20: -1, 21: 8, 23: 9,
        28: 10, 29: -1, 30: -1, 31: -1, 33: -1, 38: 11

} # If there is a -1, the state has no transactions for other states

dfa_table = (

            {
                "letter": 1, "digit": 2, "_": 1, "+": 4, "-": 5, "!": 6, "&": 7, "|": 8, 
                "/": 9, "*": 9, "=": 11, "<": 12, ">": 12, ";": 14, "(": 15, ")": 16, 
                "[": 17, "]": 18, "{": 19, "}": 20, " ": 21, "\t": 21, "\n": 23
            }, # state 0

            {
                "letter": 1, 
                "digit": 1, 
                "_": 1
            }, # state 1

            {
                "digit": 2,
                ".": 28
            }, # state 2

            {"=": 29}, # state 6

            {"&": 30}, # state 7

            {"|": 31}, # state 8

            {"=": 29}, # state 11

            {"=": 33}, # state 12

            {
                " ": 21, 
                "\t": 21
            }, # state 21

            {"\n": 23}, # state 23

            {"digit": 38}, # state 28

            {"digit": 38} # state 38

)


'''
@param state: The current state of the DFA
@param character: The next character read from the source code
@return the next state (int) of the DFA if it exists or -1 if it does not
'''
def next_state(state: int, character: str):
    
    global letter
    global digit
    global index
    global dfa

    if (character.casefold() in letter):
        character = "letter"
        
    elif (character in digit):
        character = "digit"

    ind = index.get(state) # Get the index of the dfa variable where the state transitions will be found

    if ind == -1:
        return -1 # No more transitions out of this state

    return dfa_table[ind].get(character, -1)