#include <ansi.h>
#include <npc.h>
#include <effect.h>

// 函数：生成二进制码
void SAVE_BINARY() { }


mapping PlaceIndex =
        ([
        	"新手村"	: ({0, 1}),		// 前面是序号，后面是场景编号
		"齐国" 		: ({1, 10}),
		"韩国" 		: ({2, 20}),
		"赵国" 		: ({3, 30}),
		"魏国" 		: ({4, 40}),
		"秦国" 		: ({5, 50}),
		"楚国" 		: ({6, 60}),
		"燕国" 		: ({7, 70}),
		"周国" 		: ({8, 80}),
		"桃花源" 	: ({9, 289}),
		"蜀山"		: ({10, 273}),
		"唐门"		: ({11, 324}),
		"昆仑山"	: ({12, 54}),
		"茅山"		: ({13, 269}),
		"云梦泽"	: ({14, 165}),
		"禁卫军"	: ({15, 80}),
        ]);
        
mapping CountryIndex =
        ([
        	"新手村"	: ({0, 1}),		// 前面是序号，后面是场景编号
		"齐国" 		: ({1, 10}),
		"韩国" 		: ({2, 20}),
		"赵国" 		: ({3, 30}),
		"魏国" 		: ({4, 40}),
		"秦国" 		: ({5, 50}),
		"楚国" 		: ({6, 60}),
		"燕国" 		: ({7, 70}),
		"周国" 		: ({8, 80}),
	]);        
        
int * TravelMoney = ({
	0   , 1200, 700 , 1600, 1100, 1300, 300 , 1600, 1   , 800 , 1400, 1100, 1700, 700 , 400 , 1   ,
	1200, 0   , 500 , 900 , 400 , 1500, 900 , 900 , 800 , 1200, 900 , 900 , 1900, 700 , 1400, 800 ,
	700 , 500 , 0   , 900 , 400 , 1300, 400 , 900 , 600 , 700 , 700 , 400 , 1700, 800 , 900 , 600 ,
	1600, 900 , 900 , 0   , 500 , 600 , 1300, 800 , 500 , 800 , 700 , 1300, 1000, 1600, 1700, 500 ,
	1100, 400 , 400 , 500 , 0   , 1100, 700 , 500 , 400 , 1000, 400 , 700 , 1500, 1100, 1200, 400 ,
	1300, 1500, 1300, 600 , 1100, 0   , 1400, 1600, 700 , 1000, 1300, 1700, 400 , 1800, 1900, 700 ,
	300 , 900 , 400 , 1300, 700 , 1400, 0   , 1200, 600 , 500 , 1100, 800 , 1400, 400 , 500 , 600 ,
	1600, 900 , 900 , 800 , 500 , 1600, 1200, 0   , 900 , 1500, 300 , 1200, 1700, 1600, 1700, 900 ,
	1   , 800 , 600 , 500 , 400 , 700 , 600 , 900 , 0   , 300 , 800 , 1000, 800 , 1400, 1100, 1   ,
	800 , 1200, 700 , 800 , 1000, 1000, 500 , 1500, 300 , 0   , 0   , 0   , 0   , 0   , 0   , 300 ,
	1400, 900 , 700 , 700 , 400 , 1300, 1100, 300 , 800 , 0   , 0   , 0   , 0   , 0   , 0   , 800 ,
	1100, 900 , 400 , 1300, 700 , 1700, 800 , 1200, 1000, 0   , 0   , 0   , 0   , 0   , 0   , 1000,
	1700, 1900, 1700, 1000, 1500, 400 , 1400, 1700, 800 , 0   , 0   , 0   , 0   , 0   , 0   , 800 ,
	700 , 700 , 800 , 1600, 1100, 1800, 400 , 1600, 1400, 0   , 0   , 0   , 0   , 0   , 0   , 1400,
	400 , 1400, 900 , 1700, 1200, 1900, 500 , 1700, 1100, 0   , 0   , 0   , 0   , 0   , 0   , 1100,
	1   , 800 , 600 , 500 , 400 , 700 , 600 , 900 , 1   , 300 , 800 , 1000, 800 , 1400, 1100, 1   ,
	});

int get_from_to_money(string place1, string place2)
{
	int index1, index2;
	int * message;
	if (place1==place2) return 0;
	index1 = index2=0;
	message = PlaceIndex[place1];
	if (sizeof(message)>1) index1 = message[0];
	message = PlaceIndex[place2];
	if (sizeof(message)>1) index2 = message[0];	
	if (sizeof(TravelMoney)>index1*16+index2) return TravelMoney[index1*16+index2];
	else return 0;
}

string * get_place_name()
{
	return ({ "齐国", "韩国", "赵国", "魏国", "秦国", "楚国", "燕国", "周国", "新手村", "桃花源", "蜀山", "唐门", "昆仑山", "茅山", "云梦泽","禁卫军" });
}

// 从国家到其他国家以及门派
void do_look( object npc, object who )
{
	string *name,tmp="";
	int id = getoid( npc );
	name = get_place_name();	
	name -= ({ npc->get_city_name()});
/*	
        if( present("钱票", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "带着钱票不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }
*/        
        if( present("贵重物品", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "带着贵重物品不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }		
	name -= ({ 0 });
	if(!objectp(present("战国宝典", who, 1, MAX_CARRY))) {
		tmp = ESC "领取《战国宝典》\n"+sprintf("talk %x# goto.dict\n",id);
	}
//	if (sizeof(name)==15) {
        send_user( who, "%c%s", ':', npc->get_name() + "：\n    "+"/quest/word"->get_normal_word(npc)+"\n这位" + NPC_RANK_D->get_respect(who) + "想去哪里？\n"
        	/*
                ESC "去"+name[0]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[0] ) +
                ESC "去"+name[1]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[1] ) +
                ESC "去"+name[2]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[2] ) +
                ESC "去"+name[3]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[3] ) +
                ESC "去"+name[4]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[4] ) +
                ESC "去"+name[5]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[5] ) +
                ESC "去"+name[6]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[6] ) +
                ESC "去"+name[7]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[7] ) +
                ESC "去"+name[8]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[8] ) +
                ESC "去"+name[9]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[9] ) +
                ESC "去"+name[10]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[10] ) +
                ESC "去"+name[11]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[11] ) +
                ESC "去"+name[12]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[12] ) +
                ESC "去"+name[13]+"。\n" + sprintf( "talk %x# goto.? %s\n", id, name[13] ) +
                */
                ESC "打开传送地图\n"+sprintf("talk %x# goto.map\n",id)+                
                ESC "将"+npc->get_city_name()+"作为我的回城点。\n" + sprintf( "talk %x# goto.here\n", id ) +
                tmp+
                ESC "离开。\nCLOSE\n" );
//	}
}

// 从门派到国家（不能到其他门派）
void do_look2( object npc, object who )
{
	string place1, place2;
	string index1, index2;
	string tmp ="";
	int money;
	int id = getoid( npc );
	place1 =  npc->get_fam_name();
	if (place1=="禁卫军") place1 = "周国";
/*	
        if( present("钱票", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "带着钱票不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }
*/        
        if( present("贵重物品", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "带着贵重物品不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }	
	switch( who->get_latest_city() / 100 )
	{
        case 10 : place2 = "齐国";  break;
        case 20 : place2 = "韩国";  break;
        case 30 : place2 = "赵国";  break;
        case 40 : place2 = "魏国";  break;
        case 50 : place2 = "秦国";  break;
        case 60 : place2 = "楚国";  break;
        case 70 : place2 = "燕国";  break;
        case 80 : place2 = "周国";  break;
        default : place2 = "新手村";  break;
	}
	if(!objectp(present("战国宝典", who, 1, MAX_CARRY))) {
		tmp = ESC "领取《战国宝典》\n"+sprintf("talk %x# go.dict\n",id);
	}
	money = get_from_to_money(place1, place2);
	if (npc->get_fam_name()==who->get_fam_name() || who->get_fam_name()=="" || who->get_fam_name()==0 )
		send_user( who, "%c%s", ':', npc->get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "想回到"+place2+"吗？我可以帮你这个忙。\n"
		ESC "确定\n" + sprintf( "talk %x# go\n", id ) +
		tmp+
		ESC "离开\nCLOSE\n" );	
	else
		send_user( who, "%c%s", ':', sprintf(npc->get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "想回到"+place2+"吗？我只要收 %d 金就可以了。\n"
		ESC "确定\n" + sprintf( "talk %x# go\n", id ) +
		tmp+
		ESC "离开\nCLOSE\n", money) );		
}

// 函数：对话处理
void do_goto( object npc, object who, string arg )
{
	object map, npc2,item;
	string * cmd;
	string place;
	int id = getoid(npc);
	int * message, money, *p, p2, x, y, z;
	cmd = explode( arg, " ");
	if (cmd[0]=="here")
	{
		z = get_z(who);
		if( p2 = get_jumpin(z, 10) )
		{
			who->set_latest_city(z*100+10);
			write_user( who, ECHO "您设置本城为回城点。\n" );
		}
		return;
	}
	if(cmd[0] == "map") 
	{
		send_user(who,"%c%c%s",0xa5,4,sprintf("talk %x# goto.? ",id));
		return;
	}
	if(cmd[0] == "dict") {
		if(objectp(item = "/quest/zg_dict"->want_an_zgdict(npc,who))) {
			p2 = item->move(who,-1);
			item->add_to_user(p2);
			send_user(who,"%c%s",'!',"您获得了战国宝典。");
		}		
		return;
	}
	if (sizeof(cmd)!=2) return;
	if( get_effect(who, EFFECT_TRAVEL) )
	{
                send_user( who, "%c%s", '!', "您已经在传送中。" );
                return;		
	}
/*	
        if( present("钱票", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "带着钱票不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }
*/        
        if( present("贵重物品", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "带着贵重物品不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }	
	place = npc->get_city_name();
	money = get_from_to_money(place, cmd[1]);
	if (money==0) return;
	if (cmd[0]=="?")
	{
        	send_user( who, "%c%s", ':', sprintf(npc->get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "，去"+cmd[1]+"需 %d 金，你意下如何？\n"
                ESC "好的，没有问题\n" + sprintf( "talk %x# goto.! %s\n", id, cmd[1] ) +
                ESC "离开。\nCLOSE\n", money ) );        	        	
	}
	if (cmd[0]!="!") return;
	if (who->get_cash()<money)
	{
		send_user( who, "%c%s", ':', npc->get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "，您最近手头是否有些紧？\n");
		return;
	}
        if( who->get_level()<10 )
        {
                send_user( who, "%c%s", '!', "你的等级太低了，不适合路途的颠簸。" );
                return;
        } 
        if( objectp( npc2 = who->get_quest("escort.robber#") ) && npc2->is_escort_robber() )    // 寻找蒙面人
        {
                send_user( who, "%c%s", '!', npc2->get_name()+"出现，您的行动受到影响。" );
                return;
        }        		
	message = PlaceIndex[cmd[1]];
	if (sizeof(message)==2)
	{
		z = message[1];
		if (message[0]<8) p = ({ get_jumpin(z, 10), get_jumpin(z, 11) });
		else if (message[0]==8) p = ({ get_jumpin(z, 10) });
		else p = ({ get_jumpin(z, 20) });
		p -= ({ 0 });
	        if( sizeof(p) && ( p2 = p[ random( sizeof(p) ) ] ) )
	        {
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "传送中……");	                
	                who->set_2("travel.z", z);
	                who->set_2("travel.p", p2);
	                who->set_2("travel.money", money);
	                set_effect(who, EFFECT_TRAVEL, 3);
	        }			
	}
}

void into_effect(object who)
{
	int z, p2, money;
	object map, npc2,map1;
	z = who->get_2("travel.z");
	p2 = who->get_2("travel.p");
	money = who->get_2("travel.money");
	if (z==0) 
	{
		send_user(who, "%c%c%c", 0x5a, 1, 0);
		return;
	}		
	who->delete_2("travel");
        if( who->get_level()<10 && who->get("familyuse") == 0 )
        {
                send_user( who, "%c%s", '!', "你的等级太低了，不适合路途的颠簸。" );
                send_user(who, "%c%c%c", 0x5a, 1, 0);
                return;
        } 
        if( objectp( npc2 = who->get_quest("escort.robber#") ) && npc2->is_escort_robber() )    // 寻找蒙面人
        {
                send_user( who, "%c%s", '!', npc2->get_name()+"出现，您的行动受到影响。" );
                send_user(who, "%c%c%c", 0x5a, 1, 0);
                return;
        } 	
        send_user(who, "%c%c%c", 0x5a, 1, 1);
/*        
        if( present("钱票", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "带着钱票不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }
*/        
        if( present("贵重物品", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "带着贵重物品不能旅行。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return ;
        }
        map1 = get_map_object(get_z(who));        
	who->add_to_scene( z, p2 / 1000, p2 % 1000, get_d(who), 40971, 0, 40971, 0 );
	if( (map = get_map_object(z) ) && (money > 0) ) 
	{
		if ( map1 && map1->is_changping() )
		{
			CHAR_CHAR_D->init_loop_perform(who);
			CHAR_CHAR_D->send_loop_perform(who, get_scene_object_2(who, USER_TYPE));    // 显示持续效果
		}
	        write_user( who, ECHO "您花费 %d 金来到%s。\n", money, map->get_name() );
	        who->add_cash(-money);  who->add_gold_log("pay", money);
	        who->log_money("传送", -money);                
	        "/sys/sys/count"->add_use("travel", money);
	}	
	if ( who->get("familyuse") )	//使用门派信物
		who->set("familyuse",0);
	// 去掉帮派处的影响
	who->set_2("jiguan.z", 0);
	who->set_2("jiguan.x", 0);
	who->set_2("jiguan.y", 0);				
}

void effect_break(object who)
{
	set_effect(who, EFFECT_TRAVEL, 0);
	send_user(who, "%c%c%c", 0x5a, 1, 0);
	who->delete_2("travel");
	if ( who->get("familyuse") )
	{
		who->set("familyuse",0);
		who->set_save_2("familyuse",0);
	        send_user( who, "%c%c%c%w", 0x30, 0, 8, 0 );                 

	}
}

// 从门派到国家（不能到其他门派）
void do_goto2( object npc, object who, string arg )
{
	string place1, place2;
	string index1, index2;
	object npc2,item;
	int money, p, z, x, y;
	int id = getoid( npc );
	if(arg == "dict") {
		if(objectp(item = "/quest/zg_dict"->want_an_zgdict(npc,who))) {
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",'!',"您获得了战国宝典。");
		}
		return;
	}
	place1 =  npc->get_fam_name();
	if (place1=="禁卫军") place1 = "周国";
	switch( who->get_latest_city() / 100 )
	{
        case 10 : place2 = "齐国";  break;
        case 20 : place2 = "韩国";  break;
        case 30 : place2 = "赵国";  break;
        case 40 : place2 = "魏国";  break;
        case 50 : place2 = "秦国";  break;
        case 60 : place2 = "楚国";  break;
        case 70 : place2 = "燕国";  break;
        case 80 : place2 = "周国";  break;
        default : place2 = "新手村";  break;
	}
        if( who->get_level()<10 )
        {
                send_user( who, "%c%s", '!', "你的等级太低了，不适合路途的颠簸。" );
                return;
        } 
        if( objectp( npc2 = who->get_quest("escort.robber#") ) && npc2->is_escort_robber() )    // 寻找蒙面人
        {
                send_user( who, "%c%s", '!', "蒙面人出现，您的行动受到影响。" );
                return;
        }  
	money = get_from_to_money(place1, place2);
	if (npc->get_fam_name()!=who->get_fam_name()&&who->get_fam_name()!=0 && who->get_fam_name()!="" )
	{
		if (who->get_cash()<money)
		{
			send_user( who, "%c%s", ':', npc->get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "，您最近手头是否有些紧？\n");
			return;			
		}
	}
	else money = 0;
        p = who->get_latest_city();
        if (p ==0) p = 110;
        z = p / 100;  p = get_jumpin( z, p % 100 );	
        if( p )
        {
        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "传送中……");
	        who->set_2("travel.z", z);
	        who->set_2("travel.p", p);
	        who->set_2("travel.money", money);
	        set_effect(who, EFFECT_TRAVEL, 3);
                return ;
        }
        else
        {
                write_user(who, ECHO "……可是没有任何效果。");
                return ;
        }        
}