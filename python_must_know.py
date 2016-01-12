#### Python input handlers ####
#input numbers in a string separated by spaces
string_input_list = []
for x in raw_input().split(' '):
    try:
        string_input_list.append(int(x))
    except ValueError:
        pass

#input words in a string separated by spaces
string_input_list = []
for x in raw_input().split(' '):
    string_input_list.append(x)
print string_input_list

#### Python features ####
current_key = chr(...)
if (current_key in "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"):


