# Table of identifiers found in the source program
id_table = []


''' 
@param identifier: The string of the index
@return if the funcion found the indentifier from the table, it will return the position from the table, else will add the new id in table
'''
def search_id_table(identifier: int):
    
    global id_table

    if (identifier in id_table): # Checks if the identifier is already present in the table
        return id_table.index(identifier)
    
    else: 
        id_table.append(identifier)
        return id_table.index(identifier)