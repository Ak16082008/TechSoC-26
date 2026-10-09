class Bender:
    def __init__(self,n,e,h,a,d,s,m):
        self.name=n
        self.element=e
        self.hp=h
        self.hpinitial=h
        self.att=a
        self.defense=d
        self.speed=s
        self.moves=m

    def display_stats(self):
        print(f"{self.name} ({self.element}) - HP: {self.hp}/{self.hpinitial}, Attack: {self.att}, Defense: {self.defense},Speed: {self.speed}")
        print(f"Moves: {self.moves[0][0]} {(self.moves[0][1])}, {self.moves[1][0]} {(self.moves[1][1])} , {self.moves[2][0]} {(self.moves[2][1])} , {self.moves[3][0]} {(self.moves[3][1])}")
    
    def attack(self,defender,m):
       move_index=m
       if (defender.hp>self.damage(defender,move_index)):
          defender.hp=defender.hp-self.damage(defender,move_index) 
       else :
           defender.hp=0
       print(f"{defender.name} took a damage of {self.damage(defender,move_index)} ")

    def is_fainted(self):
        return self.hp==0
    
    
    def damage(self,b2,m):
       defender=b2
       return round((self.att * self.moves[m][1]) / defender.defense)

#taking input

# Create Kael
kael = Bender("Kael", "Fire", 100, 58, 38, 88,
             [("Ember Slash", 40), ("Quick Jab", 30), ("Focus", 0), ("Flame Surge", 70)])

# Create Mira
mira = Bender("Mira", "Water", 92, 50, 45, 60,
             [("Water Whip", 35), ("Tide Push", 25), ("Mist Veil", 0), ("Tidal Wave", 60)])

# Display initial stats
kael.display_stats()
print()
print()
mira.display_stats()
print()
print()
# Kael attacks Mira with Ember Slash
kael.attack(mira, 0)
print()
mira.display_stats()
print()

# Check if Mira fainted
print(f"Mira fainted: {mira.is_fainted()}")