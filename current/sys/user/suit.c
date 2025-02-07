/***********
套装处理模块
*************/
#include <effect.h>
#include <skill.h>
#include <ansi.h>
#include <equip.h>

// 函数：生成二进制码
void SAVE_BINARY() { }
void remove_suit_effect(object who,string name,int amount);
void suit_effect(object who,string name,int amount);

// 函数：构造处理
void create() 
{ 

}
//消除套装影响
void remove_suit_equip(object who)
{
	int i,size,j,count;
	string *nTmp;	
	mapping mpTmp;
	
	mpTmp = who->get_2("suit_equip");
	if ( !mapp(mpTmp) )
		return ;
	nTmp = keys(mpTmp);
	for(i=0,size=sizeof(mpTmp);i<size;i++)
	{
		count = mpTmp[nTmp[i]]["count"];
		for(j=2;j<=count;j++)
			remove_suit_effect(who,nTmp[i],j);
	}
}
//换装备时调用
void check_suit_equip(object who)
{
	int i,size,j,count,max;
	object *nEquip,oEquip,*inv;
	mapping mpTmp;
	string *nTmp,desc;
	
	remove_suit_equip(who);
	nEquip = who->get_all_equip();
	nEquip -= ({ 0 });
	who->delete_2("suit_equip");
	for(i=0,size=sizeof(nEquip);i<size;i++)
	{
		oEquip = nEquip[i];
		if ( oEquip->is_suit() )
		{
			who->add_2(sprintf("suit_equip.%s.count",oEquip->get_suit_name()),1);
			who->set_2(sprintf("suit_equip.%s.equip.%s",oEquip->get_suit_name(),oEquip->get_name()),1);
		}
	}
	mpTmp = who->get_2("suit_equip");
	if ( !mapp(mpTmp) )
		return ;
	nTmp = keys(mpTmp);
	for(i=0,size=sizeof(mpTmp);i<size;i++)
	{
		count=mpTmp[nTmp[i]]["count"];
		for(j=2;j<=count;j++)
			suit_effect(who,nTmp[i],j);
		if ( count > max )
			max = count;
	}
	if ( max >= 2 )
		set_effect_2(who, EFFECT_USER_SUIT, 1, 5 );

	for(i=1;i<=HAND_TYPE-HEAD_TYPE+1;i++)	//已经装备的物品
	{
		"cmd/base/desc"->main(who,sprintf("%d",i));
	}
	inv = all_inventory(who,0,0);
	for( i = 0, size = sizeof(inv); i < size; i ++ )
	{
		if ( !objectp(inv[i]) || inv[i]->is_suit() != 1 )	
			continue;
		send_user( who, "%c%d%c", 0x31, getoid(inv[i]), 0 );
	}
}


//套装的影响
void suit_effect(object who,string name,int amount)
{
	int hp;
	object npc;
	
	switch(name)
	{
	case "巨象":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.hp.add",name),5);
					who->set_2(sprintf("suit_sec.%s.hp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.hp.interval",name),5);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s",name),80);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.pp.%s",name),100);
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->set_2("suit_effect.double1",30);
					who->set_2("suit_effect.double2",50);
					break;				
			}
		break;
		}
	case "萝莉套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.hp.add",name),15);
					who->set_2(sprintf("suit_sec.%s.hp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.hp.interval",name),15);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s",name),160);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.pp.%s",name),200);
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->set_2("suit_effect.double1",60);
					who->set_2("suit_effect.double2",100);
					break;				
			}
		break;
		}
       case "猛虎":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),5);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),5);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.maxhp.%s",name),100);
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.ap.%s",name),60);
					who->set_2(sprintf("suit_effect.cp.%s",name),60);
					USER_ENERGY_D->count_ap(who);
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->set_2("suit_effect.double_rate",200);
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}
       case "御姐套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),15);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),15);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.maxhp.%s",name),200);
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.ap.%s",name),120);
					who->set_2(sprintf("suit_effect.cp.%s",name),120);
					USER_ENERGY_D->count_ap(who);
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->set_2("suit_effect.double_rate",400);
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}		
	case "狂狮":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2("suit_effect.no_drop",1);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s",name),80);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.pp.%s",name),60);
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->set_2("suit_effect.double_rate",200);
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}
	case "女王套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2("suit_effect.no_drop",2);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s",name),160);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.pp.%s",name),120);
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->set_2("suit_effect.double_rate",400);
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}				
	case "猎豹":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2("suit_effect.poison",30);	
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s",name),40);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2("suit_effect.dodge",5);
					break;
				case 5:
					who->set_2("suit_effect.double_rate",200);
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}
	case "人妻套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2("suit_effect.poison",60);	
					break;
				case 3:
					who->set_2(sprintf("suit_effect.ap.%s",name),80);
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->set_2("suit_effect.dodge",10);
					break;
				case 5:
					who->set_2("suit_effect.double_rate",400);
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}		
	case "白狼":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),5);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),5);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.dp.%s",name),60);
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.cp.%s",name),80);
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->set_2("suit_effect.summon",1);
					npc = who->get("soldier");
					if ( npc && !npc->get("suit_effect") )
					{
						npc->add_max_hp((hp=npc->get_max_hp()/10));
						npc->set("suit_effect",hp);
						npc->add_dp(50);
					}
					break;				
			}
		break;
		}
	case "护士套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),15);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),15);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.dp.%s",name),120);
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.cp.%s",name),160);
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->set_2("suit_effect.summon",2);
					npc = who->get("soldier");
					if ( npc && !npc->get("suit_effect") )
					{
						npc->add_max_hp((hp=npc->get_max_hp()/20));
						npc->set("suit_effect",hp);
						npc->add_dp(100);
					}
					break;				
			}
		break;
		}
	case "雪雕":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),5);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),5);
					break;
				case 3:
					who->set_2("suit_effect.damage2",10);
					break;
					
				case 4:
					who->set_2(sprintf("suit_effect.maxmp.%s",name),60);
					USER_ENERGY_D->count_max_mp(who);
					break;
				case 5:
					who->set_2("suit_effect.damage_rate1",5);
					who->set_2("suit_effect.damage_rate3",5);
					break;
			}
		break;
		}
	case "御妹套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),15);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),15);
					break;
				case 3:
					who->set_2("suit_effect.damage2",20);
					break;
					
				case 4:
					who->set_2(sprintf("suit_effect.maxmp.%s",name),120);
					USER_ENERGY_D->count_max_mp(who);
					break;
				case 5:
					who->set_2("suit_effect.damage_rate1",10);
					who->set_2("suit_effect.damage_rate3",10);
					break;
			}
		break;
		}
	case "灵狐":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),10);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),5);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.dp.%s",name),60);
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.maxhp.%s",name),100);
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 5:
					who->set_2("suit_effect.damage_rand2",33);
					break;				
			}
		break;
		}
	case "女仆套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->set_2(sprintf("suit_sec.%s.mp.add",name),30);
					who->set_2(sprintf("suit_sec.%s.mp.time",name),time());
					who->set_2(sprintf("suit_sec.%s.mp.interval",name),30);
					break;
				case 3:
					who->set_2(sprintf("suit_effect.dp.%s",name),120);
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->set_2(sprintf("suit_effect.maxhp.%s",name),200);
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 5:
					who->set_2("suit_effect.damage_rand2",66);
					break;				
			}
		break;
		}
	}
	
}

//消除特定套装的影响
void remove_suit_effect(object who,string name,int amount)
{
	int hp;
	object npc;
	
	switch(name)
	{
	case "巨象":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.pp.%s",name));
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->delete_2("suit_effect.double1",30);
					who->delete_2("suit_effect.double2",50);
					break;				
			}
		}
       case "萝莉套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.pp.%s",name));
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->delete_2("suit_effect.double1",60);
					who->delete_2("suit_effect.double2",100);
					break;				
			}
		}
	case "猛虎":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.maxhp.%s",name));
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					who->delete_2(sprintf("suit_effect.cp.%s",name));
					USER_ENERGY_D->count_ap(who);
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->delete_2("suit_effect.double_rate");
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}
	case "御姐套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.maxhp.%s",name));
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					who->delete_2(sprintf("suit_effect.cp.%s",name));
					USER_ENERGY_D->count_ap(who);
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->delete_2("suit_effect.double_rate");
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}	
	case "狂狮":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2("suit_effect.no_drop");
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.pp.%s",name));
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->delete_2("suit_effect.double_rate");
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}
	case "女王套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2("suit_effect.no_drop");
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.pp.%s",name));
					USER_ENERGY_D->count_pp(who);
					break;
				case 5:
					who->delete_2("suit_effect.double_rate");
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}	
	case "猎豹":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2("suit_effect.poison");
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->delete_2("suit_effect.dodge");
					break;
				case 5:
					who->delete_2("suit_effect.double_rate");
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}
	case "人妻套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2("suit_effect.poison");
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.ap.%s",name));
					USER_ENERGY_D->count_ap(who);
					break;
				case 4:
					who->delete_2("suit_effect.dodge");
					break;
				case 5:
					who->delete_2("suit_effect.double_rate");
					USER_ENERGY_D->count_hit_rate(who);
					break;				
			}
		break;
		}		
	case "白狼":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.dp.%s",name));
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.cp.%s",name));
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->delete_2("suit_effect.summon");
					npc = who->get("soldier");
					if ( npc && (hp=npc->get("suit_effect")) )
					{
						npc->delete("suit_effect");
						npc->add_max_hp(-hp);
						npc->add_dp(-50);
					}
					break;				
			}
		break;
		}
	case "护士套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.dp.%s",name));
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.cp.%s",name));
					USER_ENERGY_D->count_cp(who);
					break;
				case 5:
					who->delete_2("suit_effect.summon");
					npc = who->get("soldier");
					if ( npc && (hp=npc->get("suit_effect")) )
					{
						npc->delete("suit_effect");
						npc->add_max_hp(-hp);
						npc->add_dp(-100);
					}
					break;				
			}
		break;
		}
	case "雪雕":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2("suit_effect.damage2");
					break;
					
				case 4:
					who->delete_2(sprintf("suit_effect.maxmp.%s",name));
					USER_ENERGY_D->count_max_mp(who);
					break;
				case 5:
					who->delete_2("suit_effect.damage_rate1");
					who->delete_2("suit_effect.damage_rate3");
					break;
			}
		break;
		}
	case "御妹套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2("suit_effect.damage2");
					break;
					
				case 4:
					who->delete_2(sprintf("suit_effect.maxmp.%s",name));
					USER_ENERGY_D->count_max_mp(who);
					break;
				case 5:
					who->delete_2("suit_effect.damage_rate1");
					who->delete_2("suit_effect.damage_rate3");
					break;
			}
		break;
		}
	case "灵狐":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.dp.%s",name));
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.maxhp.%s",name));
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 5:
					who->delete_2("suit_effect.damage_rand2");
					break;				
			}
		break;
		}
	case "女仆套装":	
		{
		switch(amount)
			{	
				default:
					break;
				case 2:
					who->delete_2(sprintf("suit_sec.%s",name));
					break;
				case 3:
					who->delete_2(sprintf("suit_effect.dp.%s",name));
					USER_ENERGY_D->count_dp(who);
					break;
				case 4:
					who->delete_2(sprintf("suit_effect.maxhp.%s",name));
					USER_ENERGY_D->count_max_hp(who);
					break;
				case 5:
					who->delete_2("suit_effect.damage_rand2");
					break;				
			}
		break;
		}		
		
	}
	
}

void into_effect(object who)
{
	int i,size,iTime;
	string *nTmp;	
	
	if ( !mapp(who->get_2("suit_sec") ) )
		return ;
	set_effect_2(who, EFFECT_USER_SUIT, 1, 5 ); 
	nTmp = keys(who->get_2("suit_sec"));
	size=sizeof(nTmp);
	if ( !size )
		who->delete_2("suit_sec");
	iTime = time();
	for(i=0;i<size;i++)
	{
		if ( mapp(who->get_2(sprintf("suit_sec.%s.hp",nTmp[i]))) && gone_time(who->get_2(sprintf("suit_sec.%s.hp.time",nTmp[i]))) >= who->get_2(sprintf("suit_sec.%s.hp.interval",nTmp[i])) )
		{
			who->add_hp(who->get_2(sprintf("suit_sec.%s.hp.add",nTmp[i])));
			who->set_2(sprintf("suit_sec.%s.hp.time",nTmp[i]),iTime);
		}
		if ( mapp(who->get_2(sprintf("suit_sec.%s.mp",nTmp[i]))) && gone_time(who->get_2(sprintf("suit_sec.%s.mp.time",nTmp[i]))) >= who->get_2(sprintf("suit_sec.%s.mp.interval",nTmp[i])) )
		{
			who->add_mp(who->get_2(sprintf("suit_sec.%s.mp.add",nTmp[i])));
			who->set_2(sprintf("suit_sec.%s.mp.time",nTmp[i]),iTime);
		}
	}
}
//获取套装描述
string get_suit_desc(object who, object oEquip)
{
	string ret="",name;
	int count;
	object owner;
	
	owner = oEquip->get_owner();
	if ( owner && owner->is_user() )
		who = owner;
	if ( !who )
		return oEquip->get_suit_desc();
	name = oEquip->get_suit_name();
	count = who->get_2(sprintf("suit_equip.%s.count",name));
	switch(name)
	{
	default :
		break;
	case "巨象":
		ret += sprintf("%s巨象(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s巨象头盔\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"巨象头盔"))?PPM:WHT);
		ret += sprintf("%s巨象盔甲\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"巨象盔甲"))?PPM:WHT);
		ret += sprintf("%s巨象项链\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"巨象项链"))?PPM:WHT);
		ret += sprintf("%s巨象腰带\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"巨象腰带"))?PPM:WHT);
		ret += sprintf("%s巨象之靴\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"巨象之靴"))?PPM:WHT);
		ret += sprintf("%s2件：气血每5秒恢复5点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理攻击提升80点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法术防御提高100点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：暴击免疫：受到暴击时伤害减少30％—50％\n",count>=5?PPM:WHT);
		break;	
	case "萝莉套装":
		ret += sprintf("%s萝莉套装(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s萝莉\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"萝莉"))?PPM:WHT);
		ret += sprintf("%s有三好\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"有三好"))?PPM:WHT);
		ret += sprintf("%s声萌\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"声萌"))?PPM:WHT);
		ret += sprintf("%s体柔\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"体柔"))?PPM:WHT);
		ret += sprintf("%s易推倒\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"易推倒"))?PPM:WHT);
		ret += sprintf("%s2件：气血每15秒恢复15点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理攻击提升160点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法术防御提高200点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：暴击免疫：受到暴击时伤害减少60％-100％\n",count>=5?PPM:WHT);
		break;	
	case "猛虎":
		ret += sprintf("%s猛虎(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s猛虎帽冠\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猛虎帽冠"))?PPM:WHT);
		ret += sprintf("%s猛虎皮衣\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猛虎皮衣"))?PPM:WHT);
		ret += sprintf("%s猛虎项链\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猛虎项链"))?PPM:WHT);
		ret += sprintf("%s猛虎腰带\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猛虎腰带"))?PPM:WHT);
		ret += sprintf("%s猛虎之靴\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猛虎之靴"))?PPM:WHT);
		ret += sprintf("%s2件：法力每5秒恢复5点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：气血上限增加100点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：物理攻击增加60点，\n%s法术攻击增加60点\n",count>=4?PPM:WHT,count>=4?PPM:WHT);
		ret += sprintf("%s5件：暴击率增加2％\n",count>=5?PPM:WHT);
		break;
	case "御姐套装":
		ret += sprintf("%s御姐套装(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s御姐\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"御姐"))?PPM:WHT);
		ret += sprintf("%s有三好\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"有三好"))?PPM:WHT);
		ret += sprintf("%s啤酒\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"啤酒"))?PPM:WHT);
		ret += sprintf("%s洗澡\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"洗澡"))?PPM:WHT);
		ret += sprintf("%s吃嫩草\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"吃嫩草"))?PPM:WHT);
		ret += sprintf("%s2件：法力每5秒恢复5点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：气血上限增加200点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：物理攻击增加240点，\n%s法术攻击增加120点\n",count>=4?PPM:WHT,count>=4?PPM:WHT);
		ret += sprintf("%s5件：暴击率增加4％\n",count>=5?PPM:WHT);
		break;
	case "狂狮":
		ret += sprintf("%s狂狮(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s狂狮头盔\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"狂狮头盔"))?PPM:WHT);
		ret += sprintf("%s狂狮战甲\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"狂狮战甲"))?PPM:WHT);
		ret += sprintf("%s狂狮项链\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"狂狮项链"))?PPM:WHT);
		ret += sprintf("%s狂狮腰带\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"狂狮腰带"))?PPM:WHT);
		ret += sprintf("%s狂狮之靴\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"狂狮之靴"))?PPM:WHT);
		ret += sprintf("%s2件：武器不会被击落\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理攻击增加80点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法术防御提高60点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：暴击率增加2％\n",count>=5?PPM:WHT);
		break;
	case "女王套装":
		ret += sprintf("%s女王套装(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s女王\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"女王"))?PPM:WHT);
		ret += sprintf("%s有三妙\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"有三妙"))?PPM:WHT);
		ret += sprintf("%s木马\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"木马"))?PPM:WHT);
		ret += sprintf("%s蜡烛\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"蜡烛"))?PPM:WHT);
		ret += sprintf("%s皮鞭操\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"皮鞭操"))?PPM:WHT);
		ret += sprintf("%s2件：武器不会被击落\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理攻击增加160点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法术防御提高120点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：暴击率增加4％\n",count>=5?PPM:WHT);
		break;
	case "猎豹":
		ret += sprintf("%s猎豹(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s猎豹头巾\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猎豹头巾"))?PPM:WHT);
		ret += sprintf("%s猎豹披风\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猎豹披风"))?PPM:WHT);
		ret += sprintf("%s猎豹项链\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猎豹项链"))?PPM:WHT);
		ret += sprintf("%s猎豹腰带\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猎豹腰带"))?PPM:WHT);
		ret += sprintf("%s猎豹之靴\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猎豹之靴"))?PPM:WHT);
		ret += sprintf("%s2件：毒性增加30点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理攻击提高40点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：增加5％的回避率\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：使攻击造成暴击的几率提高2％\n",count>=5?PPM:WHT);
		break;
	case "人妻套装":
		ret += sprintf("%s人妻套装(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s人妻\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"人妻"))?PPM:WHT);
		ret += sprintf("%s有三情\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"有三情"))?PPM:WHT);
		ret += sprintf("%s爱情\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"爱情"))?PPM:WHT);
		ret += sprintf("%s亲情\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"亲情"))?PPM:WHT);
		ret += sprintf("%s婚外情\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"婚外情"))?PPM:WHT);
		ret += sprintf("%s2件：毒性增加60点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理攻击提高80点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：增加10％的回避率\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：使攻击造成暴击的几率提高4％\n",count>=5?PPM:WHT);
		break;
	case "白狼":
		ret += sprintf("白狼(%d/5)\n",count);
		ret += sprintf("%s白狼皮帽\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"白狼皮帽"))?PPM:WHT);
		ret += sprintf("%s白狼皮衣\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"白狼皮衣"))?PPM:WHT);
		ret += sprintf("%s白狼项链\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"白狼项链"))?PPM:WHT);
		ret += sprintf("%s白狼腰带\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"白狼腰带"))?PPM:WHT);
		ret += sprintf("%s白狼之靴\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"白狼之靴"))?PPM:WHT);
		ret += sprintf("%s2件：法力每5秒恢复5点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理防御提高60点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法术攻击提高80点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：使茅山召唤兽的气血提升10％，\n%s物理防御提高50\n",count>=5?PPM:WHT,count>=5?PPM:WHT);
		break;
	case "护士套装":
		ret += sprintf("护士套装(%d/5)\n",count);
		ret += sprintf("%s护士\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"护士"))?PPM:WHT);
		ret += sprintf("%s有三色\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"有三色"))?PPM:WHT);
		ret += sprintf("%s白色\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"白色"))?PPM:WHT);
		ret += sprintf("%s粉色\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"粉色"))?PPM:WHT);
		ret += sprintf("%s红绿灯\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"红绿灯"))?PPM:WHT);
		ret += sprintf("%s2件：法力每15秒恢复15点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：物理防御提高120点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法术攻击提高160点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：使茅山召唤兽的气血提升20％，\n%s物理防御提高100\n",count>=5?PPM:WHT,count>=5?PPM:WHT);
		break;
	case "雪雕":
		ret += sprintf("%s雪雕(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s雪雕羽帽\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"雪雕羽帽"))?PPM:WHT);
		ret += sprintf("%s雪雕羽衣\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"雪雕羽衣"))?PPM:WHT);
		ret += sprintf("%s雪雕项链\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"雪雕项链"))?PPM:WHT);
		ret += sprintf("%s雪雕羽带\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"雪雕羽带"))?PPM:WHT);
		ret += sprintf("%s雪雕羽靴\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"雪雕羽靴"))?PPM:WHT);
		ret += sprintf("%s2件：法力每5秒恢复5点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：法术攻击造成的伤害效果增加10点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法力上限增加60点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：所承受的远程与近身物理攻击减少5％\n",count>=5?PPM:WHT);
		break;
	case "御妹套装":
		ret += sprintf("%s御妹套装(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s御妹\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"御妹"))?PPM:WHT);
		ret += sprintf("%s有三巧\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"有三巧"))?PPM:WHT);
		ret += sprintf("%s乖巧\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"乖巧"))?PPM:WHT);
		ret += sprintf("%s灵巧\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"灵巧"))?PPM:WHT);
		ret += sprintf("%s推的巧\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"推的巧"))?PPM:WHT);
		ret += sprintf("%s2件：法力每15秒恢复15点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：法术攻击造成的伤害效果增加20点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：法力上限增加120点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：所承受的远程与近身物理攻击减少10％\n",count>=5?PPM:WHT);
		break;
	case "灵狐":
		ret += sprintf("%s灵狐(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s灵狐绒帽\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"灵狐绒帽"))?PPM:WHT);
		ret += sprintf("%s灵狐皮衣\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"灵狐皮衣"))?PPM:WHT);
		ret += sprintf("%s灵狐项链\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"灵狐项链"))?PPM:WHT);
		ret += sprintf("%s灵狐腰带\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"灵狐腰带"))?PPM:WHT);
		ret += sprintf("%s灵狐之靴\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"灵狐之靴"))?PPM:WHT);
		ret += sprintf("%s2件：法力每5秒恢复10点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：增加物理防御60点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：气血上限提高100点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：增加法术所造成的伤害效果，最多33点\n",count>=5?PPM:WHT);
		break;
	case "女仆套装":
		ret += sprintf("%s女仆套装(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s女仆\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"女仆"))?PPM:WHT);
		ret += sprintf("%s有三件\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"有三件"))?PPM:WHT);
		ret += sprintf("%s猫耳\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"猫耳"))?PPM:WHT);
		ret += sprintf("%s眼镜\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"眼镜"))?PPM:WHT);
		ret += sprintf("%s蝴蝶结\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"蝴蝶结"))?PPM:WHT);
		ret += sprintf("%s2件：法力每30秒恢复30点\n",count>=2?PPM:WHT);
		ret += sprintf("%s3件：增加物理防御120点\n",count>=3?PPM:WHT);
		ret += sprintf("%s4件：气血上限提高200点\n",count>=4?PPM:WHT);
		ret += sprintf("%s5件：增加法术所造成的伤害效果，最多66点\n",count>=5?PPM:WHT);
		break;
	}
	return ret;	
}