
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_zzy();
void accept_zzy();
void give_bonus();

// ��������ȡ��������
int get_char_picid() { return 0951; }

// ���������촦��
void create()
{
        set_name( "�ɿ�������" );

        set_2( "talk", ([
                "zzy" : (: do_zzy :),
                "accept_zzy"	: (: accept_zzy :),
                "bonus_zy"	: (: give_bonus :),

        ]));

        setup();

}

// �������Ի�����
void do_look( object who )
{
	object npc,item,me=this_object();
	int id = getoid( me ),i;
        string cmd = sprintf( "talk %x# zzy\n", id );
	string tmp ="";
	if ( who->get_quest("valentine.flag") == 8 && objectp( item = present("�ɿ�����", who, 1, MAX_CARRY) ))
	tmp = ESC "���˽��ɿ�����\n" + cmd;
	send_user( who, "%c%s", ':', get_name() + "��\n    ��ͬ���ɿ�����ӵ���Ų�ͬ�ĺ��壬���Ƕ������ŨŨ�İ���\n" +
                        tmp +
                        ESC "�뿪��\nCLOSE\n" );	
}

void do_zzy()
{
	object who=this_player(); 
	object me = this_object();
        __FILE__ ->do_task_start(who, me);
}

void accept_zzy()
{
	object who=this_player(); 
	object me = this_object();
        __FILE__ ->accept_task(who, me);
}

void give_bonus(){ object who=this_player();__FILE__ ->give_bonus_2(who); }

// ��������ʼ
void do_task_start( object who, object me )
{
	if ( who->get_quest("valentine.flag") == 8 )
	{
	string cWord="";
	cWord = sprintf(me->get_name() + "��\n    С�����Ҳ����һ���ɿ������Լ��İ����𣿿��������ɿ����Ļ�е��Ҫ�㸶�������ķ���������������Ը����");
	send_user( who, "%c%s", ':', cWord +"\n"+
	ESC +sprintf("Ը�⡣\ntalk %x# accept_zzy\n",getoid(me)) +
	ESC "��Ը�⡣\nCLOSE\n" ); 
	}     
}
// �������õ��ɿ���
void accept_task( object who, object me )
{
        object item;
        string file,cWord="";
        int p,i;
	if ( who->get_quest("valentine.flag") == 8 && MAIN_D->get_host_type()!=4 )
	{
		if(USER_INVENTORY_D->count_empty_carry(who) < 3 )
		{
		        send_user(who,"%c%s",';',"������û���㹻��λ���������ճ��������������˽����");
	    		return;
		}
	        if( objectp( item = present("�ɿ�����", who, 1, MAX_CARRY) ) )
	        {
	        	item->remove_from_user();
	            	destruct(item); 
	        }
	        switch( random(4) )
	        {
	        	case 0 : file = "/item/04/0430";  break;
	                case 1 : file = "/item/04/0431";  break;
	                case 2 : file = "/item/04/0432";  break;
	                case 3 : file = "/item/04/0433";  break;
	               default : break;
	        }
	        for (i=0;i<3;i++)
	        {
	        	item = new (file);    
	                if ( item )
			{
				p = item->move(who,-1);
				item->add_to_user(p);			
			}	
		}
	     	who->set_mp(0);
		who->set_quest( "valentine.flag", 9 );
		who->add_exp(500);
		who->add_potential(10);
	       	send_user( who, "%c%s", '!', "�õ�"HIR"�ɿ���"NOR"����");
	       	write_user(who,ECHO"��Ϊ���������������õ������˽�����"+item->get_name()+"���飬�Ͻ��͸��İ������ɣ�");
	      	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"" ); 
	       	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,8,"" ); 		                        
	}

	if ( who->get_quest("valentine.flag") == 8 && MAIN_D->get_host_type()==4 )
	{
		if(USER_INVENTORY_D->count_empty_carry(who) < 3 )
		{
		        send_user(who,"%c%s",';',"������û���㹻��λ���������ճ��������������˽����");
	    		return;
		}
	        if( objectp( item = present("�ɿ�����", who, 1, MAX_CARRY) ) )
	        {
	        	item->remove_from_user();
	            	destruct(item); 
	        }
	        switch( random(4) )
	        {
	        	case 0 : file = "/item/04/0430m";  break;
	                case 1 : file = "/item/04/0431m";  break;
	                case 2 : file = "/item/04/0432m";  break;
	                case 3 : file = "/item/04/0433m";  break;
	               default : break;
	        }
	        for (i=0;i<3;i++)
	        {
	        	item = new (file);    
	                if ( item )
			{
				p = item->move(who,-1);
				item->add_to_user(p);			
			}	
		}
	     	who->set_mp(0);
		who->set_quest( "valentine.flag", 9 );
		who->add_exp(500);
		who->add_potential(10);
	       	send_user( who, "%c%s", '!', "�õ�"HIR"�ɿ���"NOR"����");
	       	write_user(who,ECHO"��Ϊ���������������õ������˽�����"+item->get_name()+"���飬�Ͻ��͸��İ������ɣ�");
	      	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"" ); 
	       	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,8,"" ); 		                        
	}
}

