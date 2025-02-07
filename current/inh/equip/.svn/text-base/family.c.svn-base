//门派信物
#include <ansi.h>
#include <map.h>
#include <effect.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/equip/equip";

private string FamilyName;

int get_equip_type() { return FAMILY_TYPE; }
string set_family_name(string family){ return FamilyName = family;}
string get_family_name() {return FamilyName;}

int get_hide() {return 0;}

//初始化师门信物的属性
void init_familyobj()
{
	string name;
	int level;
	object item=this_object();
	
	level = item->get_item_level();
	item->set_hide(0);
	name = item->get_family_name();
	if ( level > 5 )
		level = 5;
	switch(name)
	{
		case "桃花源":	
			item->set("hp%",range_value(4*level,4,20));
			break;
		case "禁卫军":			
			item->set("ap%",range_value(4*level,4,20));
			break;	
		case "蜀山":	
			item->set("cp%",range_value(4+(level-1)*3,4,16));
			item->set("ap%",range_value(4+(level-1)*3,4,16));
			break;	
		case "唐门":			
			item->set("?%",range_value(4*level,4,20)*100);
			break;	
		case "昆仑":			
			item->set("cp%",range_value(4*level,4,20));
			break;												
		case "茅山":			
			item->set("mp%",range_value(4+(level-1)*3,4,16));
			item->set("hp%",range_value(4+(level-1)*3,4,16));
			break;					
		case "云梦泽":			
			item->set("mp%",range_value(4*level,4,20));
			break;	
	}
		
}

// 函数：使用效果
int get_use_effect( object me ) {  __FILE__ ->get_use_effect_callout(me, this_object()); return 0; }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        object map, npc;
        int z, x, y, p;
        	
        if( gone_time( me->get_save_2("familyuse") ) < 60 )    // 时间限制
        {
                return 1;
        }     
        
        if( objectp( map = get_map_object( get_z(me) ) ) && map->get_map_type() == BATTLE_MAP )
        {
                send_user(me, "%c%s", '!', "在战场不能使用。");
                return 0;
        }
        if( present("贵重物品", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "带着贵重物品不能使用。");
                return 0;
        }
        if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "蒙面人出现，您的行动受到影响。");
                return 0;
        }
	if( me->is_store_open() )
	{
                send_user(me, "%c%s", '!', "摆摊不能使用");
                return 0;
        }	
        if (item->get_family_name()!="")
        {
		if( me->get_cash() < 50  )
		{
	                send_user(me, "%c%s", '!', "使用门派信物必须支付50金");
	                return 0;
	        }
	        me->add_cash(-50);
	        "sys/sys/count"->add_use("family_use",50);
	}	       
        me->set_save_2( "familyuse", time() );
        switch( me->get_fam_name() )
        {
		default : 
			p = me->get_latest_city();if (p ==0) p = 110;z = p / 100;  p = get_jumpin( z, p % 100 );break;
		case "桃花源" :	z = 289;  p = get_jumpin(z, 20);  break;
		case "蜀山" :	z = 273;  p = get_jumpin(z, 20);  break;
		case "禁卫军" :	z = 080;  p = get_jumpin(z, 20);  break;
		case "唐门" : 	z = 324;  p = get_jumpin(z, 20);  break;
		case "茅山" : 	z = 269;  p = get_jumpin(z, 20);  break;
		case "昆仑山" : z = 054;  p = get_jumpin(z, 20);  break;
		case "云梦泽" : z = 165;  p = get_jumpin(z, 20);  break;
        }

        if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 10, "传送中……");	
	        send_user( me, "%c%c%c%w", 0x30, 0, 8, 60 );   
//	        send_user( me, "%c%w%c%w", 0x50, 61, 0xff, 0 );              
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 10);
	        me->set("familyuse",1);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }
}

