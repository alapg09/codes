percept = ['Hamza','ALi','Ahmed','Saad', 'Sikandar', 'Abdullah', 'Shafqat'] 
states = ['happy','sad','angry','normal', 'excited', 'bored', 'frightened'] 
rules = ['smile','cry','shouting','coding', 'dancing', 'resting', 'running'] 

def getState(precept_value):
    index = -1
    for x in percept:
        index = index+1
        if x==precept_value:
            return states[index]

def getRules(state_value):
    index = -1
    for i in states:
        index = index+1
        if i==state_value:
            return rules[index]


def simpleReflexAgent(percept): 
    return getRules(getState(percept)) 

print("Select the person: ")
print(" 0: Hamza\n","1: ALi\n", "2: Ahmad\n","3: Saad","3: Sikandar\n","5: Abdullah\n","6: Shafqat\n")

num = int(input("Enter the person: "))

rule = simpleReflexAgent(percept[num]) 

print(rule) 
