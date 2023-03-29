''' [5 kyu] Human Readable Time

    Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)

    HH = hours, padded to 2 digits, range: 00 - 99
    MM = minutes, padded to 2 digits, range: 00 - 59
    SS = seconds, padded to 2 digits, range: 00 - 59
    The maximum time never exceeds 359999 (99:59:59)

    You can find some examples in the test fixtures.
    '''

def make_readable(tot_seconds):
    hours = tot_seconds // 3600
    minutes = (tot_seconds % 3600) // 60
    seconds = (tot_seconds % 3600) % 60
    return f'{hours:0>2}:{minutes:0>2}:{seconds:0>2}'        

    
readable_time = make_readable(359999)
print(readable_time)
