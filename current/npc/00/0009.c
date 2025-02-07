
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <cmd.h>
#include <task.h>
inherit OFFICER;

private static int min10 = -1;                   // ��λ����

// ��������������ʶ��
int is_bonus_seller() { return 1; }

// ���Լ���do_look����
int is_self_look() { return 1; }

void reset();
void do_buy( string arg );

// ��������ȡ��������
int get_char_picid() { return 5901; }

// ���������촦��
void create()
{
        set_name("��������");

        set_2( "talk", ([
                "buy"           : (: do_buy :),
        ]));
        reset();
	set("mpLegend2",([0:({32*48+22,32*48+25,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6,cmd101="",tmp;
        int id;
	"/quest/help"->send_help_tips(who, 29);
        id = getoid( this_object() );
        cmd1 = sprintf( "talk %x# buy.1\n", id );
        cmd2 = sprintf( "talk %x# buy.2\n", id );
        cmd3 = sprintf( "talk %x# buy.3\n", id );
        cmd4 = sprintf( "talk %x# buy.4\n", id );
        cmd5 = sprintf( "talk %x# buy.6\n", id );
        cmd6 = sprintf( "talk %x# buy.8\n", id );
	if ( who->get_legend(TASK_48, 21) && !who->get_legend(TASK_48, 22))
        cmd101 = sprintf(ESC HIY "������֢��1��\ntalk %x# buy.101\n",id);
	if ( who->get_legend(TASK_48, 22) && !who->get_legend(TASK_48, 23))
        cmd101 = sprintf(ESC HIY "������֢��2��\ntalk %x# buy.101\n",id);
	if ( who->get_legend(TASK_48, 24) && !who->get_legend(TASK_48, 25) )
        cmd101 = sprintf(ESC HIY "������֢��2��\ntalk %x# buy.101\n",id);
	if ( who->get_legend(TASK_48, 25) && !who->get_legend(TASK_48, 26) )
        cmd101 = sprintf(ESC HIY "������֢��3��\ntalk %x# buy.101\n",id);
        if (MAIN_D->get_host_type() != 4)
        {
	        if ( who->get_save_2("chain.save") )
	        	tmp = ESC "������������\n" + sprintf( "talk %x# buy.82\n", id );
	        else if ( who->get_save_2("chain.type") )
	        	tmp = ESC "������������\n" + sprintf( "talk %x# buy.83\n", id );
		else
			tmp = ESC "��ȡ��������\n" + sprintf( "talk %x# buy.81\n", id ) ;
	}
        send_user( who, "%c%s", ':', sprintf( get_name() + "��\n    ���� %d �㹦�£���ʲô�ҿ��԰������\n", who->get_bonus() / 10 ) + cmd101+
//                ESC "�һ���ʯ��װ����\n" + cmd1 +
                ESC "�һ�Ǳ�ܡ�\n" + cmd2 +
                ESC "�һ���Ǯ��\n" + cmd3 +
                ESC "�һ������䡣\n" + cmd4 +
//                ESC "ϴ������\n" + cmd5 +
                ESC "�ù��µ�ϴ�㡣\n" + cmd6 +
                ESC "�˽��ܻ�����\n" + sprintf( "talk %x# buy.80\n", id ) +
                tmp +
                ESC "�뿪��\nCLOSE\n" );
}

string *StoneTable = ({
        "/item/89/8901",
        "/item/89/8902",
        "/item/89/8903",
        "/item/89/8904",
        "/item/89/8905",
        "/item/89/8906",
        "/item/89/8907",
        "/item/89/8908",
        "/item/89/8909",
        "/item/89/8910",
        "/item/89/8911",
        "/item/89/8912",
        "/item/89/8913",
        "/item/89/8914",
        "/item/89/8915",
        "/item/89/8916",
        "/item/89/8917",
        "/item/89/8918",
        "/item/89/8919",
        "/item/89/8920",
        "/item/89/8921",
//      "/item/89/8922",
        "/item/89/8923",
});

int sizeof_stone = sizeof(StoneTable);

// ��������λ����
void reset()
{
        string *stone, *equip, file;

        if( ++ min10 % 6 == 0 )    // ��Сʱ����(10min * 6)
        {
                reset_eval_cost();
/*
                stone = ({ });                
                while( sizeof(stone) < 3 )
                {
                        file = StoneTable[ random(sizeof_stone) ];
                        if( member_array(file, stone) == -1 ) stone = stone + ({ file }) - ({ 0 });
                }
                add_2( "good", ([
                        "01" : stone[0],
                        "02" : stone[1],
                        "03" : stone[2],
                ]) );
                add_2( "list", ([
                        "01" : 3,
                        "02" : 3,
                        "03" : 3,
                ]) );
*/
                equip = ({ });
                while( sizeof(equip) < 5 )
                {
                        switch( random(4) )
                        {
                      default : file = WEAPON_FILE->get_weapon_file_2(60);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(70);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(60);  break;
                       case 3 : file = ARMOR_FILE->get_armor_file_2(70);  break;
                        }
                        if( member_array(file, equip) == -1 ) equip = equip + ({ file }) - ({ 0 });
                }
                add_2( "good", ([
                        "04" : equip[0],
                        "05" : equip[1],
                        "06" : equip[2],
                        "07" : equip[3],
                        "08" : equip[4],
                ]) );
                add_2( "list", ([
                        "04" : 2,
                        "05" : 2,
                        "06" : 2,
                        "07" : 2,
                        "08" : 2,
                ]) );
        }
}

// �������һ����µ�
void do_buy( string arg )
{
        object me, who;
        string cmd1, cmd2, cmd3;
        int id, type, type2, p1, p2, time, i, p;
        object item;

        me = this_object();  who = this_player();

        if( !arg ) type = 1;
        else if( sscanf(arg, "%d.%d", type, type2) ) ;
        else { type = to_int(arg);  type2 = 0; }
        
        if (type>=2 && type<=100)
        {
		if (MAIN_D->get_host_type()==6012)
		{
			send_user(who, "%c%s", '!', "������δ���ţ�");
			return;
		}         	
        }

        switch( type )
        {
      default : LIST_CMD->main( who, sprintf( "%x#", getoid(me) ) );
                return;

       case 2 : switch( type2 )
                {
              default : id = getoid(me);
                        cmd1 = sprintf( "talk %x# buy.2.1\n", id );
                        cmd2 = sprintf( "talk %x# buy.2.2\n", id );
                        cmd3 = sprintf( "talk %x# buy.2.3\n", id );
                        send_user( who, "%c%s", ':', get_name() + "��\n���㹦�¿��Զһ� 55 Ǳ�ܣ�������ζһ���\n"
                                ESC "10 ���»� 550 Ǳ�ܡ�\n" + cmd1 +
                                ESC "20 ���»� 1100 Ǳ�ܡ�\n" + cmd2 +
                                ESC "40 ���»� 2200 Ǳ�ܡ�\n" + cmd3 +
                                ESC "�뿪��\nCLOSE\n" );
                        return;
               case 1 : p1 = 100;  p2 = 550;  break;
               case 2 : p1 = 200;  p2 = 1100;  break;
               case 3 : p1 = 400;  p2 = 2200;  break;
                }

                if( who->get_bonus() < p1 )
                {
                        send_user( who, "%c%s", '!', "���Ĺ��µ���������" );
                        return;
                }

                who->add_bonus( -p1 );
                who->add_potential(p2);
                write_user(who, ECHO "���� %d �㹦�¶һ��� %d Ǳ�ܡ�", p1 / 10, p2);

                return;

       case 3 : switch( type2 )
                {
              default : id = getoid(me);
                        cmd1 = sprintf( "talk %x# buy.3.1\n", id );
                        cmd2 = sprintf( "talk %x# buy.3.2\n", id );
                        cmd3 = sprintf( "talk %x# buy.3.3\n", id );
                        send_user( who, "%c%s", ':', get_name() + "��\n���㹦�¿��Զһ� 1500 ��������ζһ���\n"
                                ESC "20 ���»� 30000 ��\n" + cmd1 +
                                ESC "40 ���»� 60000 ��\n" + cmd2 +
                                ESC "80 ���»� 120000 ��\n" + cmd3 +
                                ESC "�뿪��\nCLOSE\n" );
                        return;
               case 1 : p1 = 200;  p2 = 30000;  break;
               case 2 : p1 = 400;  p2 = 60000;  break;
               case 3 : p1 = 800;  p2 = 120000;  break;
                }

                if( who->get_bonus() < p1 )
                {
                        send_user( who, "%c%s", '!', "���Ĺ��µ���������" );
                        return;
                }

                who->add_bonus( -p1 );
                who->add_cash(p2);  who->add_gold_log("sell", p2);
                who->log_money("����", p2);                
                "/sys/sys/count"->add_income("bonus", p2);
                write_user(who, ECHO "���� %d �㹦�¶һ��� %d ��", p1 / 10, p2);

                return;
	case 4:
		send_user( who, "%c%s", ':', me->get_name() + "��\n    �һ����ɴ�������Ĵ���Ʒ��������5��Ĺ���ֵ����ȷ��Ҫ�һ���\n"+
			ESC "ȷ��\n" + sprintf("talk %x# buy.5\n", getoid(me)) +
                	ESC "�뿪��\nCLOSE\n" );			
		break;
	case 5:
/*	
		if (who->get_save_2("orgtask.type")==0)
		{
			send_user( who, "%c%s", ':', me->get_name() + "��\n    �������Ϸ���Ц�ɣ�Ҫ�һ����Ʒ��͵���ȥ�����ʷ���������ȡ��������\n"+
                		ESC "�뿪��\nCLOSE\n" );
                	return ;
		}	
*/		
		if( who->get_bonus() < 50 )
		{
			send_user( who, "%c%s", ':', me->get_name() + "��\n    ��Ĺ��»��ǲ������������ͽ�ܴ�㹦�������Ϸ�����ɡ�\n"+
                		ESC "�뿪��\nCLOSE\n" );
                	return;
		}			
                if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY )
                {
			send_user( who, "%c%s", ':', me->get_name() + "��\n    ���������������ϵĶ��������ɡ�\n"+
                		ESC "�뿪��\nCLOSE\n" );
                        return ;
                }	
                item = new ("/item/01/0006");
                if (item)
                {                	                	
                        p =item->move(who, -1);
                        item->add_to_user(p);        
			send_user( who, "%c%s", ':', me->get_name() + "��\n    �������Ҫ�Ĵ����䣬����ȥ�ʷ�����������ɡ�\n"+
                		ESC "�뿪��\nCLOSE\n" );       
                	send_user( who, "%c%s", '!', "�õ�һ��������" );                         	
                	who->add_bonus( -50 );
                }	
		break;        
/*		       
	case 6:		//ϴ����
		if ( who->get_pk() <= 0 )
		{
			send_user( who, "%c%s", ':', get_name() + "��\n    ���ں��Ϸ���Ц�ɣ�\n"
                        	ESC "����\nCLOSE\n" );
			return ;
		}
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s\n    ���Ѿ�����%d��ɱ������Ը�⻨��20�㹦���������Լ���������\n"ESC"ȷ��\ntalk %x# buy.7\n"ESC"�뿪",get_name(),who->get_pk(),getoid(this_object())));
		break;			
	case 7:
		if ( who->get_bonus() < 200 )
		{
                        send_user( who, "%c%s", ':', get_name() + ":\n    ��Ĺ��»��ǲ��㡭�������˻��ö����ƹ���Э�����������ſ��Եõ�����Ĺ��°���" );
                        return;
                }
                if ( who->get_pk() <= 0 )
                	return; 
                who->add_pk(-1);
                who->add_bonus(-200);         
                send_user( who, "%c%s", ':', get_name() + ":\n    �㻨��20�㹦��ϴ��һ��������" ) ;   	
		break;		
*/		       
	case 8:
		time = who->get_save("bonus_time");
		p1 = 100;
		if (time>0) for (i = 0;i<time;i++) p1 *= 2;
		if (p1>1600) p1 = 1600;
		id = getoid(me);
		cmd1 = sprintf( "talk %x# buy.9\n", id );
                send_user( who, "%c%s", ':', sprintf(get_name() + "��\n    ��Ը������ %d �㹦�������·���������Ե���\n"
                        ESC "ȷ��\n" + cmd1 +
                        ESC "�뿪\nCLOSE\n", p1 ) );				
		break;		
	case 9:
		time = who->get_save("bonus_time");
		p1 = 1000;
		if (time>0) for (i = 0;i<time;i++) p1 *= 2;
		if (p1>16000) p1 = 16000;	
                if( who->get_bonus() < p1 )
                {
                        send_user( who, "%c%s", ':', get_name() + "\n    ��Ĺ��»��ǲ��㡭�������˻��ö����ƹ���Э�����������ſ��Եõ�����Ĺ��°���" );
                        return;
                }		
                who->add_bonus( -p1 );
                who->add_save("bonus_time", 1);
                "/cmd/user/gift"->init_gift_point(who);
		id = getoid(me);
		cmd1 = sprintf( "look %x#\n", id );
                send_user( who, "%c%s", ':', get_name() + "��\n    �Ϸ��Ѿ�����ʵ����Ը��������ʲô��Ҫ�Ϸ��æ�ĵط���\n"
                        ESC "����\n" + cmd1 );	                
		who->log_legend("���ڹ������˴�ϴ���Ե㡣");
		break;
	case 80:
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(),
			sprintf("%s\n    �ܻ��������һ�������Ե�������Ŷ���������ȡ��һ������ʱ����Ҫ���ð�������������Ĵ���Ŷ������ӵ���ȡ��Ʒ����������Կ���ȥ�����Ӧ�ȼ�������˵��ã���ν��˵��ָ����������ȼ����Ӧ�Ĺ��ϵͳ��һ�����ʻ��������������Ҫ����Ʒ�������ӵ�ɱ������񣬵����޷���ɵ�ʱ������Կ���Ѱ�Ҹ��ְ�æŶ�������������������50�������㽫���÷ḻ�ľ��齱������Ʒ����������һ�˵���ֻ�ܽ�ȡһ���������񣬵�������������һ���ܻ�������ô������͵ȵڶ���������ȡ����ɡ���\n"ESC"�뿪",me->get_name())
		);
		break;
	case 81:
		CHAIN_D->new_chain(who,me);
		break;
	case 82:
		CHAIN_D->query_resume_chain(who,me);
		break;						        	
	case 83:
		CHAIN_D->query_save_chain(who,me);
		break;
	case 84:
		CHAIN_D->save_chain(who,me);
		break;
	case 85:
		CHAIN_D->resume_chain(who,me);
		break;						        	
        case 101: 
		if ( who->get_legend(TASK_48, 21) && !who->get_legend(TASK_48, 22) )
			send_user(who,"%c%s",':',sprintf("%s:\n    ��������������������������Ǹ����Ͳ��������������ж��ˣ����������ⶾ�ķ������������Ұɡ�\n"ESC"�������\ntalk %x# buy.102\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_48, 22) && !who->get_legend(TASK_48, 23) )
			send_user(who,"%c%s",':',sprintf("%s:\n    ���ҹ��ƣ�������Ӧ��������һ����Ϊ���ɢ�Ķ�������Դ���Ǵ����ǿ�ˮ�����ж��Ĵ��������ù�����ǿ�ˮ�����ˮ�󣬲ų��ִ�֢״�ġ�\n    ��˶������ۻ�ɢ������Ҫ������ҩ����ϲ�����Ч����ҩ��ú�ֹҪ�������Ƿ��£���������ˮ�������ⶾ�á�\n    ����ȥ�����ۻ�ɢ�ɣ�����˵�Ĺ�һ����С�۷䡢С���ϡ��ߵ������϶������ۻ�ɢ��\n    �����������alt+w���������Խ��棬��ʹ����������Ϳ��Կ��ٻص����ִ�Ŷ��\n"ESC"��������\ntalk %x# buy.103\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_48, 24) && !who->get_legend(TASK_48, 25) )
			send_user(who,"%c%s",':',sprintf("%s:\n    ����ҩ����Ҫһ����ʱ�䣬����������������ҩ�ɣ�\n"ESC"�������\ntalk %x# buy.104\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_48, 25) && !who->get_legend(TASK_48, 26) )
			send_user(who,"%c%s",':',sprintf("%s:\n    �㽫�����ҩ�ø����ӳ������Ҹ�������ǧ��Ҫ�ǵö���������������첻Ҫȥ�����ǿ�ˮ�����ˮ���ã��ǵ�Ҫ����ҩ�ø�������ã���Ҫ����ҩ����ˮ���ڣ����������α����α���\n    ����һ���£���ǧ�򲻵����ţ���������ӳ�����������������ˮ�������˶���������峤�������£������¶��ĺ���֮�ˡ�\n"ESC"��������\ntalk %x# buy.105\n"ESC"�뿪",me->get_name(),getoid(me)));
        	break;
        case 102:
		if ( who->get_legend(TASK_48, 21) && !who->get_legend(TASK_48, 22) )
        	{
        		TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48,22);
			who->add_exp(350);
			who->add_potential(20);
			who->add_cash(500);
			send_user(who,"%c%s",';',"������֢��1�� ���� 350 Ǳ�� 20 ��Ǯ 500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,109,"" );
			me->do_buy("101");
		}
        	break;
        case 103: 
		if ( who->get_legend(TASK_48, 22) && !who->get_legend(TASK_48, 23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_48,23);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,110,"������֢��2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������֢��2��");
        	}
        	break;
        case 104: 
		if ( who->get_legend(TASK_48, 24) && !who->get_legend(TASK_48, 25) )
		{
			if( !objectp( item = present("�ۻ�ɢ", who, 1, MAX_CARRY) ) )
			{
				send_user(who,"%c%s",'!',"����ۻ�ɢ��?");
				return;	
			}
			TASK_LEGEND_D->task_finish(who);
			item->remove_from_user();
			destruct(item);	
			who->add_exp(300);
			who->add_bonus(100);
			who->add_cash(1800);
			who->set_legend(TASK_48, 25);
			send_user(who,"%c%s",';',"������֢��2�� ���� 300 ���� 10 ��Ǯ 1800");			
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,110,"" );
			me->do_buy("101");
		}
		break;
        case 105: 
		if ( who->get_legend(TASK_48, 25) && !who->get_legend(TASK_48, 26) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			TASK_LEGEND_D->give_item(who,"item/98/0200",1);
        		who->set_legend(TASK_48,26);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,111,"������֢��3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������֢��3��");
        	}
        	break;
        }
}
