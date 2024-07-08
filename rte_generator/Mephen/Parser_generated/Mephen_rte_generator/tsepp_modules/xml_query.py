def find_key(nested_dict, target_key):
    for key, value in nested_dict.items():
        if key == target_key:
            return value
        elif isinstance(value, dict):
            result = find_key(value, target_key)
            if result is not None:
                return result
        elif isinstance(value, list):
            for item in value:
                if isinstance(item, dict):
                    result = find_key(item, target_key)
                    if result is not None:
                        return result
    return None

def find_unipath(nested_dict, target_type ,target_path):
    path_parts = target_path.strip("/").split("/")
    # print(path_parts)
    if "AUTOSAR" in nested_dict:
        current_dict = nested_dict["AUTOSAR"] 
    else:
        current_dict = nested_dict
    for part in path_parts:
        found = False
        # print(f'111{part}: {current_dict}')
        if isinstance(current_dict, list):
            for item in current_dict:
                if isinstance(item, dict) and item.get("SHORT-NAME") == part:
                    current_dict = item
                    found = True
                    break
        elif isinstance(current_dict, dict):
            if "AR-PACKAGES" in current_dict:
                current_dict = current_dict["AR-PACKAGES"]["AR-PACKAGE"]
                # print(f'222{part}: {current_dict}')
                if isinstance(current_dict, list):
                    for item in current_dict:
                        if item.get("SHORT-NAME") == part:
                            current_dict = item
                            found = True
                            break
                elif current_dict.get("SHORT-NAME") == part:
                    found = True
            elif "ELEMENTS" in current_dict:
               if target_type in current_dict["ELEMENTS"]:
                  current_dict = current_dict["ELEMENTS"][target_type]
               if isinstance(current_dict, list):
                    for item in current_dict:
                        if isinstance(item, dict) and item.get("SHORT-NAME") == part:
                            current_dict = item
                            found = True
                            break 
        if not found:
            return None
        # print(found)
    return current_dict

def extract_fields(data, fields):
    new_data = []
    for item in data:
        new_dict = {field: item.get(field, None) for field in fields}
        new_data.append(new_dict)
    return new_data 