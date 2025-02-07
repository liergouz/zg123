#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>
#include <effect.h>

inherit OFFICER;
inherit SAVE_F;

int iStart1;

// ��������ȡ��������
int get_char_picid() { return 8113; }
void do_welcome(string arg);
int check_dodolook(object me,object who);
void init_npc(object npc, int level);
int check_yuanfen(object who,object me);	

string get_save_file()	{ return "data/dodolook_task"SAVE_EXTENSION;}

// ���������촦��
void create()
{
        restore();
        set_name("dodolook");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
	set("mpLegend",([0:({32}),]));
        if ( !clonep(this_object()) )
        	return ;
        if (MAIN_D->get_host_type()==2)		//̨�����
        	call_out("go_there",2);
}
string get_short() 
{ 
	if ( stringp(get_real_name()) )
		return get_name() + "|" + get_real_name();
	else
		return get_name();
}
void do_look(object who) { __FILE__->do_look_call(this_object(),who); }

void do_look_call(object me,object who)
{
	int id = getoid(me);
	int iTime=time();
	
	if (MAIN_D->get_host_type()==2)
		return ;
	if ( who->get_save_2("dodolook_task.finish") )
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    Ե����ע���������ڸ���Ŷ��������һ����������Ե�ֵĻ��ᣬ����Ը�������������Ƕ�������׼���˰ɣ���Ȼ��ˣ�Ե�ֵĲ��Ծ�Ҫ��ʼ��Ŷ��\n"ESC"��ȡԵ�ֳ���\ntalk %x# welcome.101\n"ESC"ע������\ntalk %x# welcome.102\n"ESC"���Ե������\ntalk %x# welcome.107\n"ESC"����ȥԵ����վ\ntalk %x# welcome.108\n"ESC"�뿪",me->get_name(),id,id,id,id));
	else
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    Ե����ע���������ڸ���Ŷ��������һ����������Ե�ֵĻ��ᣬ����Ը�������������Ƕ�������׼���˰ɣ���Ȼ��ˣ�Ե�ֵĲ��Ծ�Ҫ��ʼ��Ŷ��\n"ESC"��ȡԵ�ֳ���\ntalk %x# welcome.101\n"ESC"ע������\ntalk %x# welcome.102\n"ESC"����Ե������\ntalk %x# welcome.103\n"ESC"����ȥԵ����վ\ntalk %x# welcome.108\n"ESC"�뿪",me->get_name(),id,id,id,id));
}

void do_welcome(string arg) { __FILE__->do_welcome_call(this_object(),arg); }

void do_welcome_call( object me,string arg )
{
	int flag, p,iTime,i,size,id,x,y,z,level;
       	object who, item,*nTeam,member,npc,map;
       	string name,*nTmp,tmp;
	mixed *mxTime;  
	
	
	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 101:
        case 10091:
        case 10101:
        	if ( !iStart1 || time() < iStart1 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���û��ʼ�أ�������鿴�ٷ���վ(zg.mop.com)���档\n"ESC"�뿪",me->get_name(),));
        		return ;	
        	}        	
        	if ( who->get_save("dodolook_yuanfen") == 2 )
        	{
			send_user(who,"%c%s",'!',"���Ѿ�����ˣ�");
			return ;	
		}
        	if ( !check_yuanfen(who,me) )
        		return ;
       		if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%s",'!',"������һ����İ���������ȡ�ɣ�");
			return ;	
		}
		who->set_save("dodolook_yuanfen",2);	//�Ѿ���ȡ��
		if ( who->get_gender() == 1 )
			item = new("item/04/0436");
		else
			item = new("item/04/0437");
		p = item->move(who,-1);
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ϲ������%s��\n"ESC"�뿪",me->get_name(),item->get_name()));
		item->add_to_user(p);
		
        	break;
        case 102:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ӵ��Ե�ֿ����û�һ��Ҫ����ȡԵ�ֳ����ٽ���Ե�����񡫣���Ȼ�㽫��ʧȥԵ�ֶԶ����ĳ齱����Ŷ����Ե������ֻΪ��Ե�����ã���ȡԵ���������Ҫ���������Ů˫����һ�ˣ�˫��Ҫ�������״̬�����ң�ӵ��Ե�ֳ�����û������ͬ��ӵ��Ե�ֳ�����û�һ���������ſ����ޡ����������������������ｻ�������һ��͸�����˫��һ��һ��Ե����װŶ����������ʧ��Ҳ���õ��ģ�����ȡ�������������������������м�Ҫ���һ��СʱŶ��\n"ESC"�뿪",me->get_name(),));
        	break;
        case 103:
        	if ( !iStart1 || time() < iStart1 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���û��ʼ�أ�������鿴�ٷ���վ(zg.mop.com)���档\n"ESC"�뿪",me->get_name(),));
        		return ;	
        	}
        	if ( check_dodolook(me,who) != 1 )
        		return ;
        	if( !( p = XY_D->get_city_point( -1, IS_CHAR_BLOCK ) ) ) return;
	        z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;
	        if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
        	name = "����ħ" + NPC_NAME_D->get_banditi_name();
		who->set_2("dodolook_task.name",name);
		who->set_2("dodolook_task.x",x);
		who->set_2("dodolook_task.y",y);
		who->set_2("dodolook_task.z",z);
		who->set_2("dodolook_task.time",time());
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��%s����%d,%d���и����%s��������˼�壬�����������֪���ٲ�������֮����氮һ������ɵ������ǵ�������Ǻ�����������Ϊ���������Ե��ɨ����С������ɺ�ǵûص��������ϣ�\n"ESC"����\ntalk %x# welcome.104\n"ESC"�뿪",me->get_name(),map->get_name(),x,y,name,id,));
        	break;
       case 104:
        	if ( check_dodolook(me,who) != 1 )
        		return ;
       		name = who->get_2("dodolook_task.name");
		if ( !name )
			return ;
		nTeam = who->get_team();
		nTeam -= ({ who });
		member = nTeam[0];
		send_user(nTeam[0],"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ӵ��Ե�ֿ����û�һ��Ҫ����ȡԵ�ֳ����ٽ���Ե�����񡫣���Ȼ�㽫��ʧȥԵ�ֶԶ����ĳ齱����Ŷ����%s�Ѿ�������Ե���������Ƿ�һͬЭ����\n"ESC"����\ntalk %x# welcome.105\n"ESC"�ܾ�\ntalk %x# welcome.106\n",me->get_name(),who->get_name(),id,id));
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȴ�%s��Ӧ��\n",me->get_name(),member->get_name()));
       		break;
       case 105:
       		nTeam = who->get_team();
       		nTeam -= ({ who,0 });
       		if ( sizeof(nTeam) != 1 )
       			return ;
       		member = who;
       		who = nTeam[0];
       		if ( check_dodolook(me,who) != 1 )
        		return ;
        	iTime = time();
       		name = who->get_2("dodolook_task.name");
       		x = who->get_2("dodolook_task.x");
       		y = who->get_2("dodolook_task.y");
       		z = who->get_2("dodolook_task.z");
       		if ( !name || !x || !y || !z )
       			return ;
       		if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
       		level = who->get_level();
       		if ( level < member->get_level() )
       			level = member->get_level();
       		level += 5;
       		who->delete_2("dodolook_task");
       		npc = new("npc/party/dodolook1");
       		npc->set_name(name);
       		npc->set( "birthday", iTime );
       		NPC_ENERGY_D->init_level(npc, level);
		init_npc(npc,level);
	        npc->add_to_scene(z, x, y, 3);
		map->add_reset(npc);    // ���븴λ�б�
		
		who->set_save_2("dodolook_task.x",x);
		who->set_save_2("dodolook_task.y",y);
		who->set_save_2("dodolook_task.z",z);
		who->set_save_2("dodolook_task.npcid",getoid(npc));
		who->set_save_2("dodolook_task.time",iTime);
		who->set_save_2("dodolook_task.name",name);
		who->set_save_2("dodolook_task.country",map->get_name());
		who->set_save_2("dodolook_task.member",member->get_number());
                send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_YUANFEN,"Ե�ֶԶ���" );     
                send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_YUANFEN,1,"��������ħ" );                  		
                send_user( who, "%c%s", '!',"�õ����� ��������ħ" );                  		
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    %s�Ѿ�ͬ���������\n",me->get_name(),member->get_name()));

		member->set_save_2("dodolook_task.x",x);
		member->set_save_2("dodolook_task.y",y);
		member->set_save_2("dodolook_task.z",z);
		member->set_save_2("dodolook_task.npcid",getoid(npc));
		member->set_save_2("dodolook_task.time",iTime);
		member->set_save_2("dodolook_task.name",name);
		member->set_save_2("dodolook_task.country",map->get_name());
		member->set_save_2("dodolook_task.member",who->get_number());
                send_user( member, "%c%c%c%w%s", 0x51, 1, 1,TID_YUANFEN,"Ե�ֶԶ���" );     
                send_user( member, "%c%c%c%w%w%s", 0x51, 1, 2,TID_YUANFEN,1,"��������ħ" );                  		
                send_user( member, "%c%s", '!',"�õ����� ��������ħ" );                  		

       		break; 	
       case 106:
       		nTeam = who->get_team();
       		nTeam -= ({ who,0 });
       		if ( sizeof(nTeam) != 1 )
       			return ;
       		member = who;
       		who = nTeam[0];
       		name = who->get_2("dodolook_task.name");
       		x = who->get_2("dodolook_task.x");
       		y = who->get_2("dodolook_task.y");
       		z = who->get_2("dodolook_task.z");
       		if ( !name || !x || !y || !z )
       			return ;       	
       		who->delete_2("dodolook_task");
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    %s�ܾ�Э�����㽫���ܻ��Ե������\n",me->get_name(),member->get_name()));
       		break;
       	case 107:
       		if ( !who->get_save_2("dodolook_task.finish") )
       			return ;
       		if ( !who->is_leader() )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㲻�Ƕӳ��������������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
       		nTeam = who->get_team();
       		nTeam -= ({ who,0 });
       		if ( sizeof(nTeam) == 0 )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ô����һ�����أ������Ե���أ����ǰ������Ե�˴�������������ȡ�����ɣ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}
       		if ( sizeof(nTeam) > 1 )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��̫���ˣ��������÷ְ���\n"ESC"�뿪",me->get_name(),));
			return ;
		}
       		member = nTeam[0];
       		if ( !inside_screen_2(who,member) 
       			|| member->get_number() != who->get_save_2("dodolook_task.member") 
       			|| who->get_number() != member->get_save_2("dodolook_task.member")  )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ô����һ�����أ������Ե���أ����ǰ������Ե�˴�������������ȡ�����ɣ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}	
       		if ( USER_INVENTORY_D->count_empty_carry(who) < 2 )
		{
			send_user(who,"%c%s",'!',"��Я������Ʒ̫����");
			return ;	
		}
		if ( USER_INVENTORY_D->count_empty_carry(member) < 2 )
		{
			send_user(who,"%c%s",'!',"�Է�Я������Ʒ̫����");
			send_user(member,"%c%s",'!',"��Я������Ʒ̫����");
			return ;	
		}
		iTime = time();
		who->delete_save_2("dodolook_task");
		member->delete_save_2("dodolook_task");
		who->set_save("dodolook_task",iTime);
		member->set_save("dodolook_task",iTime);
		if ( who->get_gender() == 1 )
		{
			item = new("item/std/9602");				
			p = item->move(who,-1);
			item->add_to_user(p);
			item = new("item/std/9603");				
			p = item->move(member,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Ե�ֶԶ��� ���� 1 �߹��� 1");
			send_user(member,"%c%s",';',"Ե�ֶԶ��� ���� 1 �߹��� 1");
		}
		else
		{
			item = new("item/std/9603");				
			p = item->move(who,-1);
			item->add_to_user(p);
			item = new("item/std/9602");				
			p = item->move(member,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Ե�ֶԶ��� ���� 1 �߹��� 1");
			send_user(member,"%c%s",';',"Ե�ֶԶ��� ���� 1 �߹��� 1");
		}
		item = new("item/04/7777");				
		p = item->move(who,-1);
		item->add_to_user(p);
		item = new("item/04/7777");				
		p = item->move(member,-1);
		item->add_to_user(p);
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_YUANFEN,1,"" );                  		
		send_user( member, "%c%c%c%w%w%s", 0x51, 1, 2,TID_YUANFEN,1,"" ); 
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, sprintf(HIY"%s��%s�ɹ������Ե�ֲ��ԣ�������ף�����ǳ�Ϊ�����������Ե�ˣ�",who->get_name(),member->get_name()) );
//		if ( who->get_save("dodolook_yuanfen") && member->get_save("dodolook_yuanfen") ) //��Ե�ֿ��ļ�¼����
			log_file("dodolook_task.txt",sprintf("%s %d %s(%d) %s(%d) �������\n",short_time(),"sys/main/main"->get_host(),who->get_name(),who->get_number(),member->get_name(),member->get_number())); 	
       		break;
       	case 108:
       		if ( !who->get_save("dodolook_task") )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �ܲ��ң���û��ͨ��Ե�ֲ��ԣ���û�л�ý���Ե����վ���ʸ������Ե����վ�͸Ͽ�ȥ�μ�Ե�ֲ��Ի�ɣ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}
        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "�����С���");
        	p = get_jumpin(805,1);
	        who->set_2("travel.z", 805);
	        who->set_2("travel.p", p);
	        set_effect(who, EFFECT_TRAVEL, 3);		
       		break;
        }
}

void go_there()
{
	object me=this_object();
	
	me->add_to_scene(802,78,43,2);
}

void init_npc(object npc, int level)
{
	int p;
	
	if ( !(p=get("test_rate")) )
		p = random(100);
	if ( p < 20)	//�����������
	{
		npc->set_skill(348,level);
		npc->set_skill(251,level);
		npc->set_skill(241,level);
		npc->set_char_picid(811);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*8);	
                npc->add_sp(npc->get_sp()*2);
                npc->add_ap(npc->get_ap()*4/5);
                npc->add_mp(npc->get_mp()/2);  
                npc->set("dodolook.type",1);              		
	}
	else if ( p < 40 )	//������ͷ�����
	{
		npc->set_skill(221,level);
		npc->set_skill(231,level);
		npc->set_char_picid(0252);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(npc->get_dp()*3);
                npc->add_max_hp(npc->get_max_hp()*4); 	
                npc->add_pp(-1*npc->get_pp()*3/10);                
                npc->add_ap(npc->get_ap()*4/5);                
                npc->add_mp(npc->get_mp()/2);  
                npc->set("dodolook.type",2);              		
	}
	else if ( p < 60 )	//�߷����������
	{
		npc->set_skill(424,level);
		npc->set_skill(423,level);
		npc->set_skill(425,level);
		npc->set_char_picid(8010);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*4); 	
                npc->add_sp(npc->get_sp());  
                npc->add_pp(npc->get_pp()*3/2);                
                npc->add_cp(npc->get_cp());
		npc->add_mp(npc->get_mp()*6);
                npc->set("dodolook.type",3);              		
	}	
	else if ( p < 70 )	//��Ѫ�ͣ�ȭ����
	{
		npc->set_skill(317,level);
		npc->set_skill(211,level);
		npc->set_char_picid(8000);
                npc->set_walk_speed(3);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/5);        
                npc->add_max_hp(npc->get_max_hp()*20); 
                npc->add_pp(-1*npc->get_pp()/5);                
                npc->add_cp(npc->get_cp()/2);                 
                npc->add_ap(npc->get_ap()*9/10);  
                npc->set("dodolook.type",4);              		
	}
	else if ( p < 90 )	//��Ѫ������߷����ͣ�Զ�̰�����
	{
		npc->set_skill(261,level);
		npc->set_char_picid(8012);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
		npc->add_dp(npc->get_dp()*9/20);
		npc->add_max_hp(npc->get_max_hp()*5); 
 		npc->add_sp(npc->get_sp()*3);
 		npc->add_pp(npc->get_pp()*9/5);
 		npc->add_mp(npc->get_mp());
 		npc->add_ap(npc->get_ap()/2);
                npc->set("dodolook.type",5);              		
	}
	else 	//ǿ���ͼ��ٻ�
	{
		npc->set_skill(414,level);
		npc->set_char_picid(8013);
                npc->set_walk_speed(4);
                npc->set_attack_speed(8);	
                npc->add_dp(npc->get_dp()*9/20);
                npc->add_ap(npc->get_ap()); 
                npc->add_max_hp(npc->get_max_hp()*5);                 
                npc->add_sp(npc->get_sp()*3);  
                npc->add_pp(npc->get_pp()*9/20);      
                npc->add_mp(npc->get_mp()*3/2);  
                npc->set("dodolook.type",6);              		
	}		

}


void task_giveup(object who)
{
	int id,iTime;
	object npc;
	
	id = who->get_save_2("dodolook_task.npcid");
	if ( !id )
		return ;
	if ( who->get_save_2("dodolook_task.finish") )
       			return ;
	iTime = who->get_save_2("dodolook_task.time");
	who->delete_save_2("dodolook_task.x");
	who->delete_save_2("dodolook_task.y");
	who->delete_save_2("dodolook_task.z");
	who->delete_save_2("dodolook_task.npcid");
	who->delete_save_2("dodolook_task.name");
	who->delete_save_2("dodolook_task.member");
	who->delete_save_2("dodolook_task.country");
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_YUANFEN,1,"" );                  		

	npc = find_any_object(sprintf("%x#",id));
	if ( npc && npc->get("birthday") == iTime )
	{
		npc->remove_from_scene();
		destruct(npc);
	}
}

int check_dodolook(object me, object who)
{
	int size;
	object *nTeam,member;
	
	if ( !who->is_leader() )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㲻�Ƕӳ������ܽ�����\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	nTeam = who->get_team();
	if ( (size=sizeof(nTeam)) == 0 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㻹�Ǻ������Ե��һ�����ɣ�\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	nTeam -= ({0});
	if ( (size=sizeof(nTeam)) == 1 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㻹�Ǻ������Ե��һ�����ɣ�\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	if ( (size=sizeof(nTeam)) > 2 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������ֻΪ��Ե����Ů˫������Ů˫����һ�ˣ��ṩ����Ŷ��\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	nTeam -= ({who});
	member = nTeam[0];
	if ( who->get_gender() == member->get_gender() )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������ֻΪ��Ե����Ů˫������Ů˫����һ�ˣ��ṩ����Ŷ��\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	if ( who->get_level() < 30 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����е�ʵ���������ҽ�ȡ������ɡ�������ҵȼ���30����\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	if ( member->get_level() < 30 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��Ķ��к������˵�ʵ�������Խ�ȡ�����񡫣�����ҵȼ���30����\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	//�Ƿ�ΪԵ�ֿ�Ƭ�û�
	if ( (who->get_save("dodolook_yuanfen") && !member->get_save("dodolook_yuanfen")) || (!who->get_save("dodolook_yuanfen") && member->get_save("dodolook_yuanfen")) )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��������Ե���𣿣������Ƕ�ӵ��Ե�ֳ����û��Ե�ֳ�����û���Ӳſ��ԣ����뻹��ȥ�Ķ�һ���Ҷ���������֪�����ɣ�\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	if ( who->get_save("dodolook_task") || member->get_save("dodolook_task") )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ����������ˣ�������˼�ٴ��鷳�㣡\n"ESC"�뿪",me->get_name(),));
		return 0;
	}
	if ( who->get_save_2("dodolook_task.npcid")  )
 	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������Ƕ�����%sû������ϴ�Ե���������Ը���������ȡ��\n"ESC"�뿪",me->get_name(),who->get_name()));
		return 0;
	}
	if ( member->get_save_2("dodolook_task.npcid") )
 	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������Ƕ�����%sû������ϴ�Ե���������Ը���������ȡ��\n"ESC"�뿪",me->get_name(),member->get_name()));
		return 0;
	}
	if ( gone_time(member->get_save_2("dodolook_task.time")) < 3600 || gone_time(who->get_save_2("dodolook_task.time")) < 3600 )
 	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ϧ���ո���������һ����������ȥ����������ħ�ˣ����ں�̫ƽ����ʱ��û�з�������ħ�������ʱ�������ɣ�\n"ESC"�뿪",me->get_name()));
		return 0;
	}
	if ( !inside_screen_2(me,who) || !inside_screen_2(who,member) )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��Ķ��Ѳ����ֳ�����\n"ESC"�뿪",me->get_name()));
		return 0;
	}
	return 1;	
}
//��ѯ�Ƿ��ж�Ӧ��Ե�ֿ�������ֵ��
int check_yuanfen(object me,object who)
{
	int status;
	string flag;
	if( me->get_save("dodolook_yuanfen") )	//�Ѿ���ѯ
		return 1;
	status = me->get_pay_money_buy_item();
	if ( status == 0 )
	{
		if ( me->get_gender() == 1 )
			flag = "1009";
		else
			flag = "1010";
                me->set("phpnum", to_int(flag));
		me->set_pay_money_buy_item(1);
		me->set_pay_type(4);
		me->set_buy_item_cmd_string( sprintf("%x# welcome.", getoid(who) ) );
		db_user_pay( me, sprintf( "%s:80\n"
               		"GET http:/""/%s/getgoods.php?t=%s&u=%d&o=%d&n=%s&ip=%s&r=%d&h=%d\r\n", MAIN_D->get_php_ip(),
               		MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), flag, get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );
log_file("php.dat", sprintf( "%s:80\n"
               		"GET http:/""/%s/getgoods.php?t=%s&u=%d&o=%d&n=%s&ip=%s&r=%d&h=%d\r\n", MAIN_D->get_php_ip(),
               		MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), flag, get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );
		return 0;
	}
	if (status!=8)
	{
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
			who->get_name()+":\n    �����������ڴ����У����Ժ�\n"
			ESC"�뿪" );
	        return 0;
	}
	me->set_save("dodolook_yuanfen",1);	//��Ե�ֿ�
	me->set_pay_money_buy_item(0);
	return 1;
}


int set_open(object who,string arg)
{
	int date1,year1,mon1,day1;
	if ( sscanf(arg ,"%d",date1) != 1 )
	{
		send_user(who,"%c%s",'!',"����ĸ�ʽ��");	
		return 0;
	}
	year1 = date1 /10000;
	mon1 = date1 % 10000 / 100;
	day1 = date1 % 10000 % 100;
	if ( !year1 || !mon1 || !day1 )
	{
		send_user(who,"%c%s",'!',"�����ʱ�䣡");	
		return 0;
	}
	iStart1 = mktime(year1,mon1,day1,0,0,0);	

	tell_user(who,"�������%s��",arg);	
	send_user(who,"%c%s",'!',"�������");	
	save();
	return 1;
}

int set_close(object who)
{
	iStart1 = 0;	
	send_user(who,"%c%s",'!',"��رգ�");	
	save();
	return 1;	
}