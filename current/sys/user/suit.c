/***********
��װ����ģ��
*************/
#include <effect.h>
#include <skill.h>
#include <ansi.h>
#include <equip.h>

// ���������ɶ�������
void SAVE_BINARY() { }
void remove_suit_effect(object who,string name,int amount);
void suit_effect(object who,string name,int amount);

// ���������촦��
void create() 
{ 

}
//������װӰ��
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
//��װ��ʱ����
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

	for(i=1;i<=HAND_TYPE-HEAD_TYPE+1;i++)	//�Ѿ�װ������Ʒ
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


//��װ��Ӱ��
void suit_effect(object who,string name,int amount)
{
	int hp;
	object npc;
	
	switch(name)
	{
	case "����":	
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
	case "������װ":	
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
       case "�ͻ�":	
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
       case "������װ":	
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
	case "��ʨ":	
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
	case "Ů����װ":	
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
	case "�Ա�":	
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
	case "������װ":	
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
	case "����":	
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
	case "��ʿ��װ":	
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
	case "ѩ��":	
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
	case "������װ":	
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
	case "���":	
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
	case "Ů����װ":	
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

//�����ض���װ��Ӱ��
void remove_suit_effect(object who,string name,int amount)
{
	int hp;
	object npc;
	
	switch(name)
	{
	case "����":	
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
       case "������װ":	
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
	case "�ͻ�":	
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
	case "������װ":	
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
	case "��ʨ":	
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
	case "Ů����װ":	
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
	case "�Ա�":	
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
	case "������װ":	
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
	case "����":	
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
	case "��ʿ��װ":	
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
	case "ѩ��":	
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
	case "������װ":	
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
	case "���":	
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
	case "Ů����װ":	
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
//��ȡ��װ����
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
	case "����":
		ret += sprintf("%s����(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s����ͷ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����ͷ��"))?PPM:WHT);
		ret += sprintf("%s�������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�������"))?PPM:WHT);
		ret += sprintf("%s��������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��������"))?PPM:WHT);
		ret += sprintf("%s��������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��������"))?PPM:WHT);
		ret += sprintf("%s����֮ѥ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����֮ѥ"))?PPM:WHT);
		ret += sprintf("%s2������Ѫÿ5��ָ�5��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������80��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4���������������100��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5�����������ߣ��ܵ�����ʱ�˺�����30����50��\n",count>=5?PPM:WHT);
		break;	
	case "������װ":
		ret += sprintf("%s������װ(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s���Ƶ�\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"���Ƶ�"))?PPM:WHT);
		ret += sprintf("%s2������Ѫÿ15��ָ�15��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������160��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4���������������200��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5�����������ߣ��ܵ�����ʱ�˺�����60��-100��\n",count>=5?PPM:WHT);
		break;	
	case "�ͻ�":
		ret += sprintf("%s�ͻ�(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s�ͻ�ñ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�ͻ�ñ��"))?PPM:WHT);
		ret += sprintf("%s�ͻ�Ƥ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�ͻ�Ƥ��"))?PPM:WHT);
		ret += sprintf("%s�ͻ�����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�ͻ�����"))?PPM:WHT);
		ret += sprintf("%s�ͻ�����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�ͻ�����"))?PPM:WHT);
		ret += sprintf("%s�ͻ�֮ѥ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�ͻ�֮ѥ"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ5��ָ�5��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3������Ѫ��������100��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4��������������60�㣬\n%s������������60��\n",count>=4?PPM:WHT,count>=4?PPM:WHT);
		ret += sprintf("%s5��������������2��\n",count>=5?PPM:WHT);
		break;
	case "������װ":
		ret += sprintf("%s������װ(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%sơ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ơ��"))?PPM:WHT);
		ret += sprintf("%sϴ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ϴ��"))?PPM:WHT);
		ret += sprintf("%s���۲�\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"���۲�"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ5��ָ�5��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3������Ѫ��������200��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4��������������240�㣬\n%s������������120��\n",count>=4?PPM:WHT,count>=4?PPM:WHT);
		ret += sprintf("%s5��������������4��\n",count>=5?PPM:WHT);
		break;
	case "��ʨ":
		ret += sprintf("%s��ʨ(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s��ʨͷ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ʨͷ��"))?PPM:WHT);
		ret += sprintf("%s��ʨս��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ʨս��"))?PPM:WHT);
		ret += sprintf("%s��ʨ����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ʨ����"))?PPM:WHT);
		ret += sprintf("%s��ʨ����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ʨ����"))?PPM:WHT);
		ret += sprintf("%s��ʨ֮ѥ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ʨ֮ѥ"))?PPM:WHT);
		ret += sprintf("%s2�����������ᱻ����\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������80��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4���������������60��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5��������������2��\n",count>=5?PPM:WHT);
		break;
	case "Ů����װ":
		ret += sprintf("%sŮ����װ(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%sŮ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Ů��"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%sľ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ľ��"))?PPM:WHT);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%sƤ�޲�\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Ƥ�޲�"))?PPM:WHT);
		ret += sprintf("%s2�����������ᱻ����\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������160��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4���������������120��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5��������������4��\n",count>=5?PPM:WHT);
		break;
	case "�Ա�":
		ret += sprintf("%s�Ա�(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s�Ա�ͷ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�Ա�ͷ��"))?PPM:WHT);
		ret += sprintf("%s�Ա�����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�Ա�����"))?PPM:WHT);
		ret += sprintf("%s�Ա�����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�Ա�����"))?PPM:WHT);
		ret += sprintf("%s�Ա�����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�Ա�����"))?PPM:WHT);
		ret += sprintf("%s�Ա�֮ѥ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�Ա�֮ѥ"))?PPM:WHT);
		ret += sprintf("%s2������������30��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3�������������40��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4��������5���Ļر���\n",count>=4?PPM:WHT);
		ret += sprintf("%s5����ʹ������ɱ����ļ������2��\n",count>=5?PPM:WHT);
		break;
	case "������װ":
		ret += sprintf("%s������װ(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%s2������������60��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3�������������80��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4��������10���Ļر���\n",count>=4?PPM:WHT);
		ret += sprintf("%s5����ʹ������ɱ����ļ������4��\n",count>=5?PPM:WHT);
		break;
	case "����":
		ret += sprintf("����(%d/5)\n",count);
		ret += sprintf("%s����Ƥñ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����Ƥñ"))?PPM:WHT);
		ret += sprintf("%s����Ƥ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����Ƥ��"))?PPM:WHT);
		ret += sprintf("%s��������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��������"))?PPM:WHT);
		ret += sprintf("%s��������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��������"))?PPM:WHT);
		ret += sprintf("%s����֮ѥ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����֮ѥ"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ5��ָ�5��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������60��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4���������������80��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5����ʹéɽ�ٻ��޵���Ѫ����10����\n%s����������50\n",count>=5?PPM:WHT,count>=5?PPM:WHT);
		break;
	case "��ʿ��װ":
		ret += sprintf("��ʿ��װ(%d/5)\n",count);
		ret += sprintf("%s��ʿ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ʿ"))?PPM:WHT);
		ret += sprintf("%s����ɫ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����ɫ"))?PPM:WHT);
		ret += sprintf("%s��ɫ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ɫ"))?PPM:WHT);
		ret += sprintf("%s��ɫ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"��ɫ"))?PPM:WHT);
		ret += sprintf("%s���̵�\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"���̵�"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ15��ָ�15��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������120��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4���������������160��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5����ʹéɽ�ٻ��޵���Ѫ����20����\n%s����������100\n",count>=5?PPM:WHT,count>=5?PPM:WHT);
		break;
	case "ѩ��":
		ret += sprintf("%sѩ��(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%sѩ����ñ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ѩ����ñ"))?PPM:WHT);
		ret += sprintf("%sѩ������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ѩ������"))?PPM:WHT);
		ret += sprintf("%sѩ������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ѩ������"))?PPM:WHT);
		ret += sprintf("%sѩ�����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ѩ�����"))?PPM:WHT);
		ret += sprintf("%sѩ����ѥ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"ѩ����ѥ"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ5��ָ�5��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������ɵ��˺�Ч������10��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4����������������60��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5���������ܵ�Զ�����������������5��\n",count>=5?PPM:WHT);
		break;
	case "������װ":
		ret += sprintf("%s������װ(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s����\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"����"))?PPM:WHT);
		ret += sprintf("%s�Ƶ���\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�Ƶ���"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ15��ָ�15��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3��������������ɵ��˺�Ч������20��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4����������������120��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5���������ܵ�Զ�����������������10��\n",count>=5?PPM:WHT);
		break;
	case "���":
		ret += sprintf("%s���(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%s�����ñ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�����ñ"))?PPM:WHT);
		ret += sprintf("%s���Ƥ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"���Ƥ��"))?PPM:WHT);
		ret += sprintf("%s�������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�������"))?PPM:WHT);
		ret += sprintf("%s�������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�������"))?PPM:WHT);
		ret += sprintf("%s���֮ѥ\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"���֮ѥ"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ5��ָ�10��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3���������������60��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4������Ѫ�������100��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5�������ӷ�������ɵ��˺�Ч�������33��\n",count>=5?PPM:WHT);
		break;
	case "Ů����װ":
		ret += sprintf("%sŮ����װ(%d/5)\n",count>=2?PPM:WHT,count);
		ret += sprintf("%sŮ��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"Ů��"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%sè��\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"è��"))?PPM:WHT);
		ret += sprintf("%s�۾�\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"�۾�"))?PPM:WHT);
		ret += sprintf("%s������\n",who->get_2(sprintf("suit_equip.%s.equip.%s",name,"������"))?PPM:WHT);
		ret += sprintf("%s2��������ÿ30��ָ�30��\n",count>=2?PPM:WHT);
		ret += sprintf("%s3���������������120��\n",count>=3?PPM:WHT);
		ret += sprintf("%s4������Ѫ�������200��\n",count>=4?PPM:WHT);
		ret += sprintf("%s5�������ӷ�������ɵ��˺�Ч�������66��\n",count>=5?PPM:WHT);
		break;
	}
	return ret;	
}