print("This Program is designed for buzzer.ino, written By @kid_ocelot")

#Declaration of global variables
#Enter note name=999  refers to "delay", with time=notelength

list_notename=[]
list_notelength=[]

def output(distance, noteType):
    return str("pn("+str(distance)+","+str(noteType)+");")

#Legacy Unfinished Function
def conv1(notename,notelength,basenote="C4"):
    notename=str(notename)

    #Raise error if notename or basenote is not in correct format
    if len(notename)!=2 or notename[0] not in "ABCDEFG" or notename[1] not in "0123456789" or len(basenote)!=2 or basenote[0] not in "ABCDEFG" or basenote[1] not in "0123456789":
        return -1

    distance = (ord(notename[0]) - ord(basenote[0]))*12 + (int(notename[1]) - int(basenote[1]))

#Main Conversion Function
def conv(notename, basenote="C4"):    
    if notename == "999":
        return 999  # 特殊值处理

    # 定义音符名称到半音的映射（C=0, C#/Db=1, D=2, ..., B=11）
    note_to_semitone = {
        'C': 0, 'C#': 1, 'Db': 1, 'D': 2, 'D#': 3, 'Eb': 3,
        'E': 4, 'F': 5, 'F#': 6, 'Gb': 6, 'G': 7, 'G#': 8,
        'Ab': 8, 'A': 9, 'A#': 10, 'Bb': 10, 'B': 11
    }
    
    def parse_note(note):
        """解析音符名称，返回字母部分和数字部分"""
        # 分离字母和数字部分
        letter_part = []
        i = 0
        while i < len(note) and not note[i].isdigit():
            letter_part.append(note[i])
            i += 1
        letter = ''.join(letter_part)
        number = int(note[i:]) if i < len(note) else 4  # 默认为4（中央C）
        return letter, number
    
    # 解析两个音符
    letter1, octave1 = parse_note(basenote)
    letter2, octave2 = parse_note(notename)
    
    # 验证输入
    if letter1 not in note_to_semitone or letter2 not in note_to_semitone:
        raise ValueError("无效的音符名称")
    
    # 计算半音距离
    semitone1 = note_to_semitone[letter1] + (octave1 * 12)
    semitone2 = note_to_semitone[letter2] + (octave2 * 12)
    
    return semitone2 - semitone1


if __name__ == "__main__":
    basenote = str(input("Enter base note (default C4): ") or "C4")
    

    while True:
        notename = str(input("Enter note name (or 'exit' to quit): "))
        if notename == "exit" or notename == "quit" or notename == "":
            break
        notelength = str(input("Enter note length: ") or 4)
        list_notename.append(notename)
        list_notelength.append(notelength)

#Convertion Stage
    for i in range(len(list_notename)):
        print(output(conv(list_notename[i], basenote), list_notelength[i]))