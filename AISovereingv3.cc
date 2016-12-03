#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Sovereignv3

#define KNIGHT_HEALTH_CRITERIUM 40


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  inline bool extra_haunted(Pos pos) {
    Cell c = cell(pos);
    if (c.haunted) {
      return true;
    }
    for (int i = 0; i < 8; i++) {
      Pos pos_aux = pos+farmer_movements[i];
      c = cell(pos_aux);
      if (c.haunted)
        return true;
    }
    return false;
  }

  inline int self_haunted(Pos pos) {
    int damage = 0;
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0 and u.type != Witch) {
          if (u.type == Farmer)
            damage += 1;
          else if (u.type == Knight)
            damage += 2;
        }
      }
    }
    Cell c = cell(pos+Left+Left);
    Unit u;
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Top+Top);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Right+Right);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Bottom+Bottom);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    return damage;
  }

    inline int other_haunted(Pos pos) {
    int damage = 0;
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player != 0 and u.type != Witch) {
          if (u.type == Farmer)
            damage += 1;
          else if (u.type == Knight)
            damage += 2;
        }
      }
    }
    Cell c = cell(pos+Left+Left);
    Unit u;
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Top+Top);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Right+Right);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Bottom+Bottom);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    return damage;
  }
/*
  inline bool self_haunted(Pos pos) {
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      Unit u = unit(c.id);
      if (u.id != -1 and u.player == 0 and u.type != Witch)
        return true;
    }
    Cell c = cell(pos+Left+Left);
    Unit u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Top+Top);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Right+Right);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Bottom+Bottom);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    return false;
  }*/
  
  inline bool knighted(Pos pos) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+knight_movements[i]);
        if (c.id != -1) {
          Unit u = unit(c.id);
          if (u.player != 0 and u.type == Knight)
            return true;
        }
    }

   return false;
  }

  inline bool knighted2(Pos pos,int& health) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+knight_movements[i]);
        if (c.id != -1) {
          Unit u = unit(c.id);
          if (u.player != 0 and u.type == Knight) {
            health = u.health;
            return true;
          }
        }
    }

   return false;
  }


  inline bool check_farmer_escape(Pos pos,UnitType unitType, int health) {
    if (unitType == Farmer) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      /*if (extra_haunted(pos)) // !
        return false;*/
      if (c.id != -1)
        return false;
      /*if (knighted(pos))
        return false;*/
      return true;
    }
    else if (unitType == Knight){
      //return false;
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      /*if (extra_haunted(pos)) // !
        return false;*/
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        if (u.type == Knight) 
          return false;
        if (u.type == Farmer) 
          return true;

      }
      //int health_en;
      //if (knighted2(pos,health_en) and 1.5*health < health_en)
      /*if (knighted(pos) and health < 60)
        return false;*/
      return true;
    }
  }

  inline bool check_targetable_escape(Pos pos,UnitType unitType, int health) {
    /*if (not extra_haunted(pos) and not knighted(pos))
      return true;*/
    Cell c = cell(pos);
    if (not c.haunted)
      return true;
    else return false;
  }



  /*

  inline bool check_farmer(Pos pos) {
    Cell c = cell(pos);
    if (c.type == Wall)
        return false;
    if (c.haunted)
        return false;
    if (c.id != -1)
        return false;
    if (knighted(pos))
      return false;
    return true;
  }

    inline bool check_targetable(Pos pos) {
    Cell c = cell(pos);
    if (c.owner != 0)
      return true;
    else
      return false;
  }


  */


  inline bool check_farmer_opt(Pos pos,UnitType unitType, int health, bool escape) {
    if (unitType == Farmer) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.id != -1)
        return false;
      if (c.haunted)
        return false;
      if (extra_haunted(pos) and not escape)
        return false;
      if (knighted(pos) and not escape)
        return false;
      return true;
    }
    else if (unitType == Knight) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      if (extra_haunted(pos) and not escape) // !
        return false;
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        if (u.type == Knight) 
          return true;
        if (u.type == Farmer) 
          return true;

      }
      return true;
    }
    else if (unitType == Witch) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        return true;
      }
      if (self_haunted(pos) > 1 and round() > 20) { // (abans self_haunted > 0) ROUND: clauissim!!! > 20 EP EP
        return false;
      }
      return true;
    }
    
    else
      return false;
  }

  inline bool check_targetable_opt(Pos pos,UnitType unitType, int health, bool escape) {
    if (unitType == Farmer) {
    if (escape)
      return true;
    Cell c = cell(pos);
    if (c.owner != 0)
      return true;
    else
      return false;
    }
    else if (unitType == Knight) {
      if (escape)
        return true;
      Cell c = cell(pos);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        else {
          if (u.type == Farmer)
            return true;
          else if (u.type == Knight) {
            return true;
           /*if (health > u.health)
              return true;
            else
              return false;*/
          }
          else
            return false;
        }
      }
      else
        return false;
    }
    else if (unitType == Witch) {
      /*Cell c = cell(pos);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        else if (u.type == Witch)
          return false;
        else if (u.type == Knight)
          return true;
        
        //else if (u.type == Farmer)
          //return true;
        //else
          //return true;
          
      }*/
      /*if (round() <= 40 and other_haunted(pos) > 4)
        return true;*/
      /*if (round() > 40 and other_haunted(pos) > 0)
        return true;*/
      if (other_haunted(pos) > 1) // > = 0 ?
        return true;
    }
    return false;
  }

  


   inline bool check_farmer(Pos pos,UnitType unitType, int health) {
    if (unitType == Farmer) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      if (extra_haunted(pos)) // !
        return false;
      if (c.id != -1)
        return false;
      if (knighted(pos))
        return false;
      return true;
    }
    else if (unitType == Knight){
      //return false;
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.haunted)
        return false;
      if (extra_haunted(pos)) // !
        return false;
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        if (u.type == Knight) 
          return true;
        if (u.type == Farmer) 
          return true;

      }
      //int health_en;
      //if (knighted2(pos,health_en) and 1.5*health < health_en)
      /*if (knighted(pos) and health < 60)
        return false;*/
      return true;
    }
    else if (unitType == Witch) {
      Cell c = cell(pos);
      if (c.type == Wall)
        return false;
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        if (u.type == Witch)
          return false;
        return true;
      }
      if (self_haunted(pos) > 1 and round() > 20) { // (abans self_haunted > 0) ROUND: clauissim!!! > 20 EP EP
        return false;
      }
      /*if (self_haunted(pos) > 5 and round() <= 20) {
        return false;
      }*/
      return true;
    }
    
    else
      return false;
  }
  
  inline bool check_targetable(Pos pos,UnitType unitType, int health) {
    if (unitType == Farmer) {
    Cell c = cell(pos);
    if (c.owner != 0)
      return true;
    else
      return false;
    }
    else if (unitType == Knight) {
      Cell c = cell(pos);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        else {
          if (u.type == Farmer)
            return true;
          else if (u.type == Knight) {
            return true;
           /*if (health > u.health)
              return true;
            else
              return false;*/
          }
          else
            return false;
        }
      }
      else
        return false;
    }
    else if (unitType == Witch) {
      /*Cell c = cell(pos);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0)
          return false;
        else if (u.type == Witch)
          return false;
        else if (u.type == Knight)
          return true;
        
        //else if (u.type == Farmer)
          //return true;
        //else
          //return true;
          
      }*/
      /*if (round() <= 40 and other_haunted(pos) > 4)
        return true;*/
      /*if (round() > 40 and other_haunted(pos) > 0)
        return true;*/
      if (other_haunted(pos) > 1) // > = 0 ?
        return true;
    }
    return false;
  }

  inline bool bfs(int id, bool escape) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);

    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    set<Pos> s_visited; // TODO: this set is not necessary, it could be done with the map
    UnitType unitType = u.type;
    int n = 0;
    vector<Dir> mov(8);
    if (u.type == Farmer or u.type == Witch) {
      n = 4;
      vector<Dir> mov_aux(n);
      for (int i = 0; i < n; i++)
        mov_aux[i] = farmer_movements[i];
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = mov_aux[i];
    }
    else if (u.type == Knight) {
      n = 8;
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = farmer_movements[i];

    }
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < n; i++) {
        if (check_farmer_opt(pos+mov[i],unitType,u.health,escape)) {
          if (check_targetable_opt(pos+mov[i],unitType,u.health,escape)) {
            //FOUND
            m.insert(make_pair(pos+mov[i],pos));
            Pos pos_dir = pos+mov[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            if (u.pos+Left == pos_aux) {
              command(id,Left);
            }
            else if (u.pos+Top == pos_aux) {
              command(id,Top);
            }
            else if (u.pos+Right == pos_aux) {
              command(id,Right);
            }
            else if (u.pos+Bottom == pos_aux) {
              command(id,Bottom);
            }
            else if (unitType == Knight) {
              if (u.pos+BR == pos_aux) {
                command(id,BR);
              }
              else if (u.pos+RT == pos_aux) {
                command(id,RT);
              }
              else if (u.pos+TL == pos_aux) {
                command(id,TL);
              }
              else if (u.pos+LB == pos_aux) {
                command(id,LB);
              }
            }
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+mov[i]) == s_visited.end()) {
              s_visited.insert(pos+mov[i]); // no necessari pels farmers, sí pels knights
              q.push(pos+mov[i]);
              m.insert(make_pair(pos+mov[i],pos));
            }
          }
        }
      }
    }
    // TODO: if safe, command none. Else, escape. Or health...
    /*bool b;
    if (extra_haunted(u.pos) or knighted(u.pos)) {
      cerr << "YEP" << endl;
      b = bfs_escape(id);
    }*/
    //if (not b)
      command(id,None);
    return false;
  }



  void move_farmer(int id) {
    // TODO: decide wheter command(None)
    // TODO: health criterium?
    Unit u = unit(id);
    bool escape = false;
    if (extra_haunted(u.pos) or knighted(u.pos))
      escape = true;
    bfs(id,escape);
  }

  void move_knight(int id) {
    // TODO: decide wheter command(None)
    Unit u = unit(id);
    bool escape = false;
    if (extra_haunted(u.pos) or (knighted(u.pos) and u.health < KNIGHT_HEALTH_CRITERIUM))
      escape = true;
    bfs(id,escape);
  }

  void move_witch(int id) {
    bfs(id,false);
    // TODO: maybe I should force the witch to "escape" if it's deactivated.
  }

  void moveAllFarmers() {
    // TODO: cooperation?
    f = farmers(0);
    for (int i = 0; i < f.size(); i++)
        move_farmer(f[i]);
  }

  void moveAllKnights() {
    // TODO: cooperation?
    k = knights(0);
    for (int i = 0; i < k.size(); i++)
        move_knight(k[i]);
  }

  void moveAllWitches() {
    // TODO: cooperation?
    // TODO: defensive?
    w = witches(0);
    for (int i = 0; i < w.size(); i++)
        move_witch(w[i]);
    
  }
  
  void moveAllUnits() {
    moveAllWitches();
    moveAllKnights();
    moveAllFarmers();
  }



  // TODO:  pre-render matirx

  /**
   * Types and attributes for your player can be defined here.
   */

  vector<int> f;
  vector<int> k;
  vector<int> w;
  Dir knight_movements[8] = {Bottom,BR,Right,RT,Top,TL,Left,LB};
  //Dir farmer_movements[4] = {Left,Top,Right,Bottom};
  //Dir farmer_movements[4] = {Left,Top,Right,Bottom};
  Dir farmer_movements[8] = {Left,Top,Right,Bottom,BR,RT,TL,LB};

  /**
   * Play method, invoked once per each round.
   */

  virtual void play () {
    moveAllUnits();
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
