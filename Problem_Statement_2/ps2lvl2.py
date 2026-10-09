import random

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
   
    @staticmethod
    def attack(attacker,defender,m,duel):
       
       print(f"{attacker.name} used {attacker.moves[m][0]}!")
       multiplier,_=Duel.type_multiplier(attacker,defender)
       
       #labels
       if multiplier==2:
           print("Super Effective!")
           duel.super_effective_num += 1
       elif multiplier==0.5:
            print("Not very effective... ")
       else :
           pass
       
       c=Duel.critical_multiplier()
       if c==2:
           print("Critical Hit!")
           duel.critical_num += 1
       base_damage = (attacker.att * attacker.moves[m][1]) / defender.defense
       final_damage = base_damage *c*multiplier
       final_damage = max(1, round(final_damage))

       if (defender.hp>final_damage):
          defender.hp=defender.hp-final_damage 

       else :
           defender.hp=0
       print(f"{defender.name} took a damage of {final_damage} ")
       print(f"{defender.name} HP : {defender.hp}/{defender.hpinitial}")

       
    def is_fainted(self):
        return self.hp==0
    
    

class Duel :
    def __init__(self,a,b):
        self.bender1=a
        self.bender2=b
        self.critical_num=0
        self.super_effective_num=0
    @staticmethod
    def critical_multiplier():
        critical_chance = 0.10  # 10% chance
        is_critical = random.random() < critical_chance  
        if is_critical:
            return 2
        else:
            return 1
    @staticmethod
    def selector(bender1,bender2):
       if bender1.speed > bender2.speed:
          first,second= bender1, bender2
          
          return first,second
       elif bender2.speed > bender1.speed:
          first,second= bender2, bender1
            
          return first,second
       else:
       # Speed tie - random selection
           first, second = random.choice([(bender1, bender2), (bender2, bender1)])
           
           return first,second

    @staticmethod
    def type_multiplier(attacker,defender): 
        if attacker.element=="Water" and defender.element=="Fire":
           return 2,"Super Effective"
        elif attacker.element=="Fire" and defender.element=="Water":
            return  0.5,"Weak"
        elif attacker.element=="Fire" and defender.element=="Air":
            return  2, "Super Effective"
        elif attacker.element=="Air" and defender.element=="Fire":
            return  0.5,"Weak"
        elif attacker.element=="Air" and defender.element=="Earth":
            return  2, "Super Effective"
        elif attacker.element=="Earth" and defender.element=="Air":
            return  0.5,"Weak"
        elif attacker.element=="Earth" and defender.element=="Water":
            return  2,"Super Effective"
        elif attacker.element=="Water" and defender.element=="Earth":
            return  0.5,"Weak"
        else:
            return 1,"Neutral"
    

    """ 
    Duel start announcement
    Turn-by-turn combat log
    Elemental advantage notifications
    Critical hit notifications
    HP updates after each attack
    Duel end result with winner
    """
    
    def start_duel(self):
       print(f" === DUEL BEGINS! ===")
       print()
       print(f"{self.bender1.name} ({self.bender1.element}, HP: {self.bender1.hp}/{self.bender1.hpinitial}) VS {self.bender2.name} ({self.bender2.element}, HP: {self.bender2.hp}/{self.bender2.hpinitial}))")
       i=1
       attacker,defender=self.selector(self.bender1,self.bender2)
       
       print()
       print()
       while attacker.hp>0 and defender.hp>0:
             print(f"Turn {i}:")
             print(f"{attacker.name} goes first!")
            
             m=random.choice([0,1,2,3])
             Bender.attack(attacker,defender,m,self)
             attacker,defender=defender,attacker
             i=i+1
             print()
       if attacker.hp==0:
           winner=defender.name
           print(f"{attacker.name} fainted!")
           print(f"🏆 {defender.name} wins the duel!")
       else:
           winner=attacker.name
           print(f"{defender.name} fainted!")
           print(f"🏆 {attacker.name} wins the duel!")

       print("Duel Summary:")
       print(f"- Winner: {winner}")
       print(f"- Turns: {i-1}")
       print(f"- Critical Hits: {self.critical_num}")
       print(f"- Super Effective Hits: {self.super_effective_num}")


#taking input

# Create Benders
kael = Bender("Kael", "Fire", 100, 58, 38, 88,
             [("Ember Slash", 40), ("Quick Jab", 30), ("Focus", 0), ("Flame Surge", 70)])

mira = Bender("Mira", "Water", 92, 50, 45, 60,
             [("Water Whip", 35), ("Tide Push", 25), ("Mist Veil", 0), ("Tidal Wave", 60)])

# Start duel
duel = Duel(kael, mira)
duel.start_duel()

# Turn 1: Kael uses Ember Slash (move 0)
# Turn 2: Mira uses Water Whip (move 0), Critical Hit!
