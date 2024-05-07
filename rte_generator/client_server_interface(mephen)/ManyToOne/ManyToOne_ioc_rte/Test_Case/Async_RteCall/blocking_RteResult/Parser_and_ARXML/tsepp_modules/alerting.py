from termcolor import colored
import textwrap
import json

def print_lookupinfo(node, pathname):
   print("\n" + "*" * 100) 
   wrapped_message = textwrap.fill(f' According to {node} now need to find {pathname}', width=90) 
   print(colored('[INFORMATION]: ', 'blue') + wrapped_message)
   print("*" * 100 + "\n")

def print_message(messages, message_type='success'):
    print("\n" + "*" * 100)
    if isinstance(messages, list):
        for message in messages:
            wrapped_message = textwrap.fill(message, width=90)
            if message_type.lower() == 'success':
                print(colored('[SUCCESS]: ', 'green') + wrapped_message)
            elif message_type.lower() == 'error':
                print(colored('[ERROR]: ', 'red') + wrapped_message)
            elif message_type.lower() == 'warning':
                print(colored('[WARNING]: ', 'yellow') + wrapped_message)
            elif message_type.lower() == 'info': 
                print(colored('[INFORMATION]: ', 'blue') + wrapped_message) 
            else:
                raise ValueError("Invalid message type. Please choose from 'success', 'error', or 'warning'.")
    print("*" * 100 + "\n")

def print_nodeinfo(node):
    print("\n" + "*" * 85)

    str_list = []
    
    if isinstance(node, dict):
        # 將字典的 key 和 value 轉換為字串，並用換行符分隔
        for key, value in  node.items():
            str_list.append(f'KEY:{key}')
            str_list.append(f'VALUE:{type(value)}')
    else:
        str_list.append(f' the node contains: {node}')

    str_list.append(f' The structure that is currently printed is of type {type(node)}')
    
    # str_joined = '\n'.join(node_list)
    # wrapped_message = textwrap.fill(str_joined, width=1000)
    # print(colored('[INFORMATION]: ', 'blue') + wrapped_message)
    print(colored('[INFORMATION]: ', 'blue') + '\n')
    for i in range(0, len(str_list), 2):
        print(str_list[i])
        if i < len(str_list) - 1:
            print(str_list[i+1]+ '\n')
 
    print("*" * 85 + "\n")
