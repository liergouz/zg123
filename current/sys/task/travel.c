#include <ansi.h>
#include <npc.h>
#include <effect.h>

// ���������ɶ�������
void SAVE_BINARY() { }


mapping PlaceIndex =
        ([
        	"���ִ�"	: ({0, 1}),		// ǰ������ţ������ǳ������
		"���" 		: ({1, 10}),
		"����" 		: ({2, 20}),
		"�Թ�" 		: ({3, 30}),
		"κ��" 		: ({4, 40}),
		"�ع�" 		: ({5, 50}),
		"����" 		: ({6, 60}),
		"���" 		: ({7, 70}),
		"�ܹ�" 		: ({8, 80}),
		"�һ�Դ" 	: ({9, 289}),
		"��ɽ"		: ({10, 273}),
		"����"		: ({11, 324}),
		"����ɽ"	: ({12, 54}),
		"éɽ"		: ({13, 269}),
		"������"	: ({14, 165}),
		"������"	: ({15, 80}),
        ]);
        
mapping CountryIndex =
        ([
        	"���ִ�"	: ({0, 1}),		// ǰ������ţ������ǳ������
		"���" 		: ({1, 10}),
		"����" 		: ({2, 20}),
		"�Թ�" 		: ({3, 30}),
		"κ��" 		: ({4, 40}),
		"�ع�" 		: ({5, 50}),
		"����" 		: ({6, 60}),
		"���" 		: ({7, 70}),
		"�ܹ�" 		: ({8, 80}),
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
	return ({ "���", "����", "�Թ�", "κ��", "�ع�", "����", "���", "�ܹ�", "���ִ�", "�һ�Դ", "��ɽ", "����", "����ɽ", "éɽ", "������","������" });
}

// �ӹ��ҵ����������Լ�����
void do_look( object npc, object who )
{
	string *name,tmp="";
	int id = getoid( npc );
	name = get_place_name();	
	name -= ({ npc->get_city_name()});
/*	
        if( present("ǮƱ", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "����ǮƱ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }
*/        
        if( present("������Ʒ", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "���Ź�����Ʒ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }		
	name -= ({ 0 });
	if(!objectp(present("ս������", who, 1, MAX_CARRY))) {
		tmp = ESC "��ȡ��ս�����䡷\n"+sprintf("talk %x# goto.dict\n",id);
	}
//	if (sizeof(name)==15) {
        send_user( who, "%c%s", ':', npc->get_name() + "��\n    "+"/quest/word"->get_normal_word(npc)+"\n��λ" + NPC_RANK_D->get_respect(who) + "��ȥ���\n"
        	/*
                ESC "ȥ"+name[0]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[0] ) +
                ESC "ȥ"+name[1]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[1] ) +
                ESC "ȥ"+name[2]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[2] ) +
                ESC "ȥ"+name[3]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[3] ) +
                ESC "ȥ"+name[4]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[4] ) +
                ESC "ȥ"+name[5]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[5] ) +
                ESC "ȥ"+name[6]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[6] ) +
                ESC "ȥ"+name[7]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[7] ) +
                ESC "ȥ"+name[8]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[8] ) +
                ESC "ȥ"+name[9]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[9] ) +
                ESC "ȥ"+name[10]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[10] ) +
                ESC "ȥ"+name[11]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[11] ) +
                ESC "ȥ"+name[12]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[12] ) +
                ESC "ȥ"+name[13]+"��\n" + sprintf( "talk %x# goto.? %s\n", id, name[13] ) +
                */
                ESC "�򿪴��͵�ͼ\n"+sprintf("talk %x# goto.map\n",id)+                
                ESC "��"+npc->get_city_name()+"��Ϊ�ҵĻسǵ㡣\n" + sprintf( "talk %x# goto.here\n", id ) +
                tmp+
                ESC "�뿪��\nCLOSE\n" );
//	}
}

// �����ɵ����ң����ܵ��������ɣ�
void do_look2( object npc, object who )
{
	string place1, place2;
	string index1, index2;
	string tmp ="";
	int money;
	int id = getoid( npc );
	place1 =  npc->get_fam_name();
	if (place1=="������") place1 = "�ܹ�";
/*	
        if( present("ǮƱ", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "����ǮƱ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }
*/        
        if( present("������Ʒ", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "���Ź�����Ʒ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }	
	switch( who->get_latest_city() / 100 )
	{
        case 10 : place2 = "���";  break;
        case 20 : place2 = "����";  break;
        case 30 : place2 = "�Թ�";  break;
        case 40 : place2 = "κ��";  break;
        case 50 : place2 = "�ع�";  break;
        case 60 : place2 = "����";  break;
        case 70 : place2 = "���";  break;
        case 80 : place2 = "�ܹ�";  break;
        default : place2 = "���ִ�";  break;
	}
	if(!objectp(present("ս������", who, 1, MAX_CARRY))) {
		tmp = ESC "��ȡ��ս�����䡷\n"+sprintf("talk %x# go.dict\n",id);
	}
	money = get_from_to_money(place1, place2);
	if (npc->get_fam_name()==who->get_fam_name() || who->get_fam_name()=="" || who->get_fam_name()==0 )
		send_user( who, "%c%s", ':', npc->get_name() + "��\n��λ" + NPC_RANK_D->get_respect(who) + "��ص�"+place2+"���ҿ��԰������æ��\n"
		ESC "ȷ��\n" + sprintf( "talk %x# go\n", id ) +
		tmp+
		ESC "�뿪\nCLOSE\n" );	
	else
		send_user( who, "%c%s", ':', sprintf(npc->get_name() + "��\n��λ" + NPC_RANK_D->get_respect(who) + "��ص�"+place2+"����ֻҪ�� %d ��Ϳ����ˡ�\n"
		ESC "ȷ��\n" + sprintf( "talk %x# go\n", id ) +
		tmp+
		ESC "�뿪\nCLOSE\n", money) );		
}

// �������Ի�����
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
			write_user( who, ECHO "�����ñ���Ϊ�سǵ㡣\n" );
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
			send_user(who,"%c%s",'!',"�������ս�����䡣");
		}		
		return;
	}
	if (sizeof(cmd)!=2) return;
	if( get_effect(who, EFFECT_TRAVEL) )
	{
                send_user( who, "%c%s", '!', "���Ѿ��ڴ����С�" );
                return;		
	}
/*	
        if( present("ǮƱ", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "����ǮƱ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }
*/        
        if( present("������Ʒ", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "���Ź�����Ʒ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }	
	place = npc->get_city_name();
	money = get_from_to_money(place, cmd[1]);
	if (money==0) return;
	if (cmd[0]=="?")
	{
        	send_user( who, "%c%s", ':', sprintf(npc->get_name() + "��\n��λ" + NPC_RANK_D->get_respect(who) + "��ȥ"+cmd[1]+"�� %d ����������Σ�\n"
                ESC "�õģ�û������\n" + sprintf( "talk %x# goto.! %s\n", id, cmd[1] ) +
                ESC "�뿪��\nCLOSE\n", money ) );        	        	
	}
	if (cmd[0]!="!") return;
	if (who->get_cash()<money)
	{
		send_user( who, "%c%s", ':', npc->get_name() + "��\n��λ" + NPC_RANK_D->get_respect(who) + "���������ͷ�Ƿ���Щ����\n");
		return;
	}
        if( who->get_level()<10 )
        {
                send_user( who, "%c%s", '!', "��ĵȼ�̫���ˣ����ʺ�·;�ĵ�����" );
                return;
        } 
        if( objectp( npc2 = who->get_quest("escort.robber#") ) && npc2->is_escort_robber() )    // Ѱ��������
        {
                send_user( who, "%c%s", '!', npc2->get_name()+"���֣������ж��ܵ�Ӱ�졣" );
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
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "�����С���");	                
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
                send_user( who, "%c%s", '!', "��ĵȼ�̫���ˣ����ʺ�·;�ĵ�����" );
                send_user(who, "%c%c%c", 0x5a, 1, 0);
                return;
        } 
        if( objectp( npc2 = who->get_quest("escort.robber#") ) && npc2->is_escort_robber() )    // Ѱ��������
        {
                send_user( who, "%c%s", '!', npc2->get_name()+"���֣������ж��ܵ�Ӱ�졣" );
                send_user(who, "%c%c%c", 0x5a, 1, 0);
                return;
        } 	
        send_user(who, "%c%c%c", 0x5a, 1, 1);
/*        
        if( present("ǮƱ", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "����ǮƱ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }
*/        
        if( present("������Ʒ", who, 1, MAX_CARRY*4) )
        {
                send_user(who, "%c%s", '!', "���Ź�����Ʒ�������С�");
//              write_user(me, ECHO "��������û���κ�Ч����");
                return ;
        }
        map1 = get_map_object(get_z(who));        
	who->add_to_scene( z, p2 / 1000, p2 % 1000, get_d(who), 40971, 0, 40971, 0 );
	if( (map = get_map_object(z) ) && (money > 0) ) 
	{
		if ( map1 && map1->is_changping() )
		{
			CHAR_CHAR_D->init_loop_perform(who);
			CHAR_CHAR_D->send_loop_perform(who, get_scene_object_2(who, USER_TYPE));    // ��ʾ����Ч��
		}
	        write_user( who, ECHO "������ %d ������%s��\n", money, map->get_name() );
	        who->add_cash(-money);  who->add_gold_log("pay", money);
	        who->log_money("����", -money);                
	        "/sys/sys/count"->add_use("travel", money);
	}	
	if ( who->get("familyuse") )	//ʹ����������
		who->set("familyuse",0);
	// ȥ�����ɴ���Ӱ��
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

// �����ɵ����ң����ܵ��������ɣ�
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
			send_user(who,"%c%s",'!',"�������ս�����䡣");
		}
		return;
	}
	place1 =  npc->get_fam_name();
	if (place1=="������") place1 = "�ܹ�";
	switch( who->get_latest_city() / 100 )
	{
        case 10 : place2 = "���";  break;
        case 20 : place2 = "����";  break;
        case 30 : place2 = "�Թ�";  break;
        case 40 : place2 = "κ��";  break;
        case 50 : place2 = "�ع�";  break;
        case 60 : place2 = "����";  break;
        case 70 : place2 = "���";  break;
        case 80 : place2 = "�ܹ�";  break;
        default : place2 = "���ִ�";  break;
	}
        if( who->get_level()<10 )
        {
                send_user( who, "%c%s", '!', "��ĵȼ�̫���ˣ����ʺ�·;�ĵ�����" );
                return;
        } 
        if( objectp( npc2 = who->get_quest("escort.robber#") ) && npc2->is_escort_robber() )    // Ѱ��������
        {
                send_user( who, "%c%s", '!', "�����˳��֣������ж��ܵ�Ӱ�졣" );
                return;
        }  
	money = get_from_to_money(place1, place2);
	if (npc->get_fam_name()!=who->get_fam_name()&&who->get_fam_name()!=0 && who->get_fam_name()!="" )
	{
		if (who->get_cash()<money)
		{
			send_user( who, "%c%s", ':', npc->get_name() + "��\n��λ" + NPC_RANK_D->get_respect(who) + "���������ͷ�Ƿ���Щ����\n");
			return;			
		}
	}
	else money = 0;
        p = who->get_latest_city();
        if (p ==0) p = 110;
        z = p / 100;  p = get_jumpin( z, p % 100 );	
        if( p )
        {
        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "�����С���");
	        who->set_2("travel.z", z);
	        who->set_2("travel.p", p);
	        who->set_2("travel.money", money);
	        set_effect(who, EFFECT_TRAVEL, 3);
                return ;
        }
        else
        {
                write_user(who, ECHO "��������û���κ�Ч����");
                return ;
        }        
}