
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;
void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 7805; }

// ���������촦��
void create()
{
        set_name( "����" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//        set("level", 6);
//        set("legend", ({ 32*2+22 }));
//	set("mpLegend",([5:({32*2+22}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
        string tmp="";

/*	if( who->get_level() >= 5 )
        {
                if( !who->get_legend(TASK_NEWBIE_02, 23) )
                {
			tmp = sprintf(ESC"Ȱ�ϴ󲮻ؼ�\ntalk %x# welcome.1\n",getoid(this_object()));
                }
        }      */
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        send_user( who, "%c%s", ':', get_name() + "��\n�Ҽ���ͷ�ӳ����˻�û�������óԷ��˰ɣ������˵���ѽ�������ʲô�����˰ɡ�\n"
        				+ tmp +
        				ESC"�뿪"
        	 );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,j,k,size,*tmp=({}),*res=({}),p;
	object who,item,item1,*inv;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 22))
			send_user(who,"%c%s",':',sprintf("%s:\n    ��������Ϊ��ҵ������������һ�ܣ����������ϳ����˵����ڻ�û������Ҳ��Ҫ�Է��ˣ����ܻ����������������ú��Ҽƽϣ�һ��������������̰ɣ���������û��һ��ì���أ�����������ҵ��ϴ󲮣�����ȰȰ����\n    ��һ��Ҳ����ȥ�𴦣��ʹ������Ĺȣ����ܾ����Ҹ����ɡ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_NEWBIE_02, 22) && !who->get_legend(TASK_NEWBIE_02, 23))	
			send_user(who,"%c%s",':',sprintf("%s:\n    ������Ը�������������û�ҵ����أ�������ĳ�ʲô�����˰ɣ�����ȥһ�����ˣ���ɵþ�������ҵ���ѽ���Ҷ��쵣�����ˣ�\n"ESC"�뿪",me->get_name()));
			
		break;
	case 2:
		if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 22) )
		{
			who->set_legend(TASK_NEWBIE_02, 22);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HUANJIAO,"�Ĺ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HUANJIAO,1,"���޼������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���޼������");	
		}
		break;
	}
}