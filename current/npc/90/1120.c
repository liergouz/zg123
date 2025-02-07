
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <cmd.h>
#include <ansi.h>
#include <task.h>
inherit OFFICER;

// ������ʦ��ʶ��
int is_master() { return 1; }

// ��������ȡ��������
string get_fam_name() { return "�һ�Դ"; }

// ��������ȡ����˳��
int get_fam_order() { return 2; }

// ��������ȡ��������
int get_char_picid() { return 9112; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���Լ���do_look����
int is_self_look() { return 1; }

int get_level() { return 120; }

void do_skill();
void do_quest();
void do_giveup();
void do_giveup2();
void do_apprentice(string arg);
void accept_quest();
void task_info();
void valentine( string arg );
void valentine2();
// ���������촦��
void create()
{
        set_name( "��������" );
        
        set_skill(0211, 120);
        set_skill(0371, 120);
        set_skill(0212, 120);
        set_skill(0372, 120);
        set_skill(0316, 120);
        set_skill(0373, 120);
        set_skill(0317, 120);
        set_skill(0374, 120);
        set_skill(0319, 120);
        set_skill(0375, 120);
        set_2( "talk", ([
                "skills"                : (: do_skill :),
                "quest"                 : (: do_quest :),
                "giveup"                : (: do_giveup :),
                "giveup2"               : (: do_giveup2 :),
                "apprentice"            : (: do_apprentice :),                        
                "accept_quest"            : (: accept_quest :),
                "task_info"             : (: task_info :),                  	
                "valentine"             : (: valentine :),                  	
                "valentine2"             : (: valentine2 :),                  	
        ]));
        set_2( "good", ([
        	"01" : "/item/70/0010",
        	"02" : "/item/70/1020",                
        	"03" : "/item/60/0010",
        	"04" : "/item/60/1020",
        	"05" : "/item/61/0010",
        	"06" : "/item/61/1020",
        	"07" : "/item/65/0010",
        	"08" : "/item/65/1020",
        	"09" : "/item/66/0010",
        	"10" : "/item/66/1020",                
        	"11" : "/item/88/0010",
        	"12" : "/item/88/1020",
        	"13" : "/item/87/1010",
        	"14" : "/item/87/1020",              
        ]) ); 
        setup();
}

// ������������ֽ���
void do_look( object who )
 {
	object npc,me=this_object();
	int i,id = getoid( me );
	object item;
	string cmd,tmp ="";
	string cmds ="��\n��λС�������������̫����ʲô�£��������ҿ��Ǻ�æ�ģ�����ʲôҪ�µĻ������ҵ�����ͽ�ܰɡ�\n";
 	if( who->get_quest("valentine.flag") == 5)
	{
        cmd = sprintf( "talk %x# valentine.1\n", id );
	tmp = ESC "���˽ڵĴ�˵\n" + cmd;
	send_user( who, "%c%s", ':', get_name() + cmds +
                        tmp +
                        ESC "�뿪\nCLOSE\n" );	
     	}
 	else if( who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.type")!= 1)
	{
        cmd = sprintf( "talk %x# valentine.3\n", id );
	tmp = ESC "��ʹ������\n" + cmd;
	send_user( who, "%c%s", ':', get_name() + cmds +
                        tmp +
                        ESC "�뿪\nCLOSE\n" );	
     	}
 	else if( who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.bonus") == 1 && objectp( item = present("��������Ҫ����֬", who, 1, MAX_CARRY)) && objectp( item = present("��������Ҫ������", who, 1, MAX_CARRY)) && objectp( item = present("��������Ҫ��ͷ��", who, 1, MAX_CARRY)))
	{
        cmd = sprintf( "talk %x# valentine.4\n", id );
	tmp = ESC "��ʹ������\n" + cmd;
	send_user( who, "%c%s", ':', get_name() + cmds +
                        tmp +
                        ESC "�뿪\nCLOSE\n" );	
     	}
 	else if( who->get_quest("valentine.flag") == 7 && !objectp( item = present("�ɿ�����", who, 1, MAX_CARRY)))
	{
        cmd = sprintf( "talk %x# valentine.6\n", id );
	tmp = ESC "�ɿ�����\n" + cmd;
	send_user( who, "%c%s", ':', get_name() + cmds +
                        tmp +
                        ESC "�뿪\nCLOSE\n" );	
     	}

     	else 
	 TASK_MASTER_D->do_look( who, this_object() ); 
}

// ����������ѧϰ����
void do_skill(  ) { LEARN_CMD->learn_menu( this_player(), this_object() ); }

// ��������ȡ����
void do_quest(  ) { TASK_MASTER_D->do_quest( this_player(), this_object() ); }

// ������ȡ������
void do_giveup(  ) { TASK_MASTER_D->do_giveup( this_player(), this_object() ); }

// ������ȡ������2
void do_giveup2(  ) { TASK_MASTER_D->do_giveup2( this_player(), this_object() ); }

// ��������ʦ
void do_apprentice( string arg  ) { TASK_APPRENTICE_D->do_apprentice( this_player(), this_object(), arg ); }
//��������
void accept_quest(  ) { TASK_MASTER_D->accept_quest( this_player(), this_object() ); }
//������Ϣ
void task_info(  ) { TASK_MASTER_D->task_info( this_player(), this_object() ); }

// �����İ���Ʒ
int accept_object( object player, object obj ) 
{
	object who = this_object();
	return TASK_MASTER_D->accept_object( who, player, obj ); 
}

// ������ɾ��ʦ�ż���
void delete_family_skill( object who )
{
        mapping skls;
        object file;
        string *name, result;
        int skill, level, i, size;

        skls = get_skill_dbase();
        name = keys(skls);
        size = sizeof(name);
        result = sprintf( "���������롰%s�����£���ʧ��", get_fam_name() );
        for( i = 0; i < size; i ++ )
        {
                skill = to_int( name[i] );
                if( level = who->get_skill(skill) )
                {
                        if( file = load_object( SKILL->get_skill_file(skill) ) ) 
                                result = sprintf("%s%s(%d) ", result, file->get_name(), level);
                        else    result = sprintf("%s%s(%d) ", result, name[i], level);
                }
                who->delete_skill(skill);
        }

        who->log_legend(result);
}


void valentine( string arg )
{
        object me = this_object();
        __FILE__ ->do_valentine(me, arg);
}

void do_valentine( object me, string arg )
{
	int flag,p,i,x,y,z,id;
	object who,item,map,item214_1,item214_2,item214_3;
        string cmd,cWord,tmp="";	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        	case 1:
        		if( who->get_quest("valentine.flag") == 5)
        		{
	        		cWord = sprintf(me->get_name() + "��\n    �ɰ���С������������ǲ���ѯ���й����˽ڵ����鰡��\n    �����뵱����Ҳ�������Ե���ʹ����Ů�������˽ڿ쵽�ˣ���Ҳ����һ���أ�С������ʲô�õĻ�ױƷ�Ƽ�������\n");
				send_user( who, "%c%s", ':', cWord +"\n"+
				ESC +sprintf("�������\ntalk %x# valentine.2\n",getoid(me)) +
				ESC "�뿪��\nCLOSE\n" ); 
        		}
			break;
        	case 2:
			if( who->get_quest("valentine.flag") == 5)
			{
	        		if( who->get_quest("valentine.flag") == 5)
	        		{
		     	     	     	who->add_exp(500);
		     	     	     	who->set_quest( "valentine.flag", 6 );
		     	     	     	who->set_quest( "valentine.type", 0 );
		             	     	send_user( who, "%c%c%c%w%w%w%s", 0x51, 1, 4,TID_VALENTINE,5,0,"" );
			     	     	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,5,"" ); 
			     	     	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"" ); 
	        		}
			}
			break;
        	case 3:
			if( who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.type")!= 1)
			{
				z = ({10,20,30,40,50,60,70})[random(7)];
				if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) ) return ;
			        x = ( p % 1000000 ) / 1000;  y = p % 1000;
				if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
				who->set_quest("valentine.name","���˽���å");
				who->set("valentine.x",x);
				who->set("valentine.y",y);
				who->set("valentine.z",z);        		
	        		cWord = sprintf(me->get_name() + "��\n    �����뵱����Ҳ�������Ե���ʹ����Ů�������˽ڿ쵽�ˣ���Ҳ����һ���أ�С������ʲô�õĻ�ױƷ�Ƽ�������\n    ���û�еĻ�������ȥһ��%s���ģ�%d��%d���ɣ�ȥ����������Щ��å���������ϻ���ʹ��������ֺ�Ů���ӵ���֬�����Ӻ�ͷ���أ�\n",map->get_name(),x,y);
				send_user( who, "%c%s", ':', cWord +"\n"+
				ESC +sprintf("��������\ntalk %x# valentine2\n",getoid(me)) +
				ESC "�뿪��\nCLOSE\n" ); 
			}
			break;
        	case 4:
			if( who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.bonus") == 1 && objectp( item = present("��������Ҫ����֬", who, 1, MAX_CARRY)) && objectp( item = present("��������Ҫ������", who, 1, MAX_CARRY)) && objectp( item = present("��������Ҫ��ͷ��", who, 1, MAX_CARRY)))
			{
	        		cWord = sprintf(me->get_name() + "��\n    �ԶԶԣ�������Щ�������ҵúúô��һ�£��������������ң��һ�������������ܵõ��ɿ����ġ�\n");
				send_user( who, "%c%s", ':', cWord +"\n"+
				ESC +sprintf("�������\ntalk %x# valentine.5\n",getoid(me)) +
				ESC "�뿪��\nCLOSE\n" ); 
			}
			break;
        	case 5:
			if( who->get_quest("valentine.flag") == 6 && who->get_quest("valentine.bonus") == 1 && objectp( item = present("��������Ҫ����֬", who, 1, MAX_CARRY)) && objectp( item = present("��������Ҫ������", who, 1, MAX_CARRY)) && objectp( item = present("��������Ҫ��ͷ��", who, 1, MAX_CARRY)))
			{
				if( !objectp( item214_1 = present("��������Ҫ����֬", who, 1, MAX_CARRY) ) )
				{
					send_user( who, "%c%s", '!', "������û����������Ҫ����֬");
					return;
				}          
				if( !objectp( item214_1 = present("��������Ҫ������", who, 1, MAX_CARRY) ) )
				{
					send_user( who, "%c%s", '!', "������û����������Ҫ������");
					return;
				} 
				if( !objectp( item214_1 = present("��������Ҫ��ͷ��", who, 1, MAX_CARRY) ) )
				{
					send_user( who, "%c%s", '!', "������û����������Ҫ��ͷ��");
					return;
				} 
				if( objectp( item214_1 = present("��������Ҫ����֬", who, 1, MAX_CARRY) ) )
				{
					item214_1->remove_from_user();
					destruct(item214_1); 
				}          
				if( objectp( item214_1 = present("��������Ҫ������", who, 1, MAX_CARRY) ) )
				{
					item214_1->remove_from_user();
					destruct(item214_1); 
				} 
				if( objectp( item214_1 = present("��������Ҫ��ͷ��", who, 1, MAX_CARRY) ) )
				{
					item214_1->remove_from_user();
					destruct(item214_1); 
				} 
	     	     	     	who->add_exp(500);
	     	     	     	who->add_potential(10);
	     	     	     	who->set_quest( "valentine.flag", 7 );
	             	     	send_user( who, "%c%c%c%w%w%w%s", 0x51, 1, 4,TID_VALENTINE,6,0,"" );
		     	     	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,6,"" ); 
		     	     	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"" ); 
			}
			break;
        	case 6:
			if( who->get_quest("valentine.flag") == 7 && !objectp( item = present("�ɿ�����", who, 1, MAX_CARRY)))
			{
	        		cWord = sprintf(me->get_name() + "��\n    лл���ˣ�С����������˽������Ҫ��һ�����������Ů��õ�廨��Ů���������ɿ�����ร������ɿ���ȥ����������ҿɲ�֪���������������е��ɿ��������������Ӧ��֪���������ɿ����������ɿ����ġ�\n");
				send_user( who, "%c%s", ':', cWord +"\n"+
				ESC +sprintf("��������\ntalk %x# valentine.7\n",getoid(me)) +
				ESC "�뿪��\nCLOSE\n" ); 
			}
			break;
        	case 7:
			if( who->get_quest("valentine.flag") == 7 && !objectp( item = present("�ɿ�����", who, 1, MAX_CARRY)))
			{
	        		item214_1 = new ("item/04/0425");    //�ɿ�����
	                        if (item214_1)
	                        {
	                                if( USER_INVENTORY_D->can_carry(who, item214_1)  >=1 )
	                                {
	                                        p =item214_1->move(who, -1);
	                                        item214_1->add_to_user(p);
			                        send_user( who, "%c%s", '!', "�õ�"HIR"�ɿ�����"NOR"һЩ");
						send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"���˽�����" ); 
						send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,7,"�ɿ�����" ); 		                        
						send_user( who, "%c%s", '!', "����ȡ�����˽����񡪡������ɿ�������");
	                                }       
	                                else
	                                {
	                                	destruct(item214_1); 
	                                	send_user( who, "%c%s", '!', "������û�п�λ��");
	                                }
	                        }
			}
			break;
       	}
}

void valentine2(  ) { "/sys/party/valentine"->do_valentine5_call( this_player(), this_object() ); }

