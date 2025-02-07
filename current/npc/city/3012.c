
// �Զ����ɣ�/make/npc/make8012

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

void do_out();
void do_record();

// ��������ȡ��������
int get_char_picid() { return 0600; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�Թ�����");
        set_city_name("�Թ�");

        set_2( "talk", ([
                "out"           : (: do_out :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("in", 13);
        set("out", 11);
//        set("level",83);
//        set("legend",({32*28+4}));
 	set("mpLegend",([80:({32*28+4}),110:({32*39+9})]));
 	set("mpLegend2",([80:({32*28+6}),]));
        setup();
}

string get_master() { return CITY_ZHAO->get_master(); }
string get_master_2() { return CITY_ZHAO->get_master_2(); }
string get_master_3() { return CITY_ZHAO->get_master_3(); }

void do_look( object who ) 
{ 
	string tmp="";
	object me = this_object();

	if ( (who->get_level() >= 80 && !who->get_legend(TASK_28,4)) || (who->get_legend(TASK_28,4) && !who->get_legend(TASK_28,6)))
	{
		tmp = sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_level() >= 110 && !who->get_legend(TASK_39,9) )
		tmp += sprintf(ESC HIY "��Ը\ntalk %x# welcome.4\n",getoid(me));

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GUARDER_D->do_look_2( who, me ); 
	
}
void do_out() { GUARDER_D->do_out( this_player(), this_object() ); }

void do_record() { GUARDER_D->do_record( this_player(), this_object() ); }

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_28,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ǵ�ԭ����������͸�Ź��죬��˵����·�����ǽ��ͬ�У�������ˣ����в����ͻ�ʧȥ�ټ�������ֻ���ҵ������ʬ�׺����ҵĻ�����˼��Ȼ�и��������еľ�ס��֮���Բ�����Ϊ�ˣ�����Ϊ��Ҷ����ɾ��������ֵ�������һĻĻ�Ҿ磬��Ȼƽ��������Ҳ������ͣ������ܾ�������Ц����ɭɭ�ģ�˵�����Ĺ��죬���Ծ����°����ǵõ�����쭶�������ЪЪ�ţ����Ǵ�Ҷ��ľ���ս�ģ�ˮ���Һȣ�����Ҳ������������������ʼ������ԭ���Ǹ����������Ľ�ʬ������ѡ��������������̵����������þ����ĵط��ȱܿ���Ⱥ���������ţ��ֿ�����ʱ������Ѫ��߷�������������Σ�����ڵ������ǵ�ְ����Ǽ���������������������ǰȥ����������У������һ��̫ƽ�ĵ�·��\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_28,4) && !who->get_legend(TASK_28,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ţ�û�����У�Ī������������һ��ֻ����֮�����Ĵ�˵��\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_28,5) && !who->get_legend(TASK_28,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ɱ���ˣ������ˣ�ʲô��û�����£�̫�Ź��ˣ����ǽ�ʬ��ʲô������л��л�أ�׳ʿ���Ѿ�Ϊ�������ڳ���һ�����ˣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
	case 2:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_28,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_28,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,46,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_28,5) && !who->get_legend(TASK_28,6) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/final/15/1521",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_28,6);
			who->add_exp(49000);
			who->add_potential(690);
			who->add_cash(47000);
			send_user(who,"%c%s",';',"�������� ���� 49000 Ǳ�� 690 ��Ǯ 47000 ǿЧ��� 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,46,"" );
        	}
        	break; 
        case 4:
		if ( who->get_level() >= 110 && !who->get_legend(TASK_39,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵ��ֵܵ����ز����Ѿ�����һϢ�ˡ�\n    ���Ⱳ��������Ը���Ǽ�һ���عܼң��عܼ���һ�����Ƕ�ı���ˣ�����˵���عܼҵ�һЩ�¼����൱���������������������֮�ʣ�ֻϣ���ܼ����عܼ�һ�档\n    ����ȥ�������Ը�����عܼ���\n    \n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break; 
        case 5:
        	if ( who->get_level() >= 110 && !who->get_legend(TASK_39,9) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_39,9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,67,"��Ը" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ը");
        	}
        	break; 
        case 99:
        	GUARDER_D->do_look_2( who, me ); 
        	break;     
        }
}