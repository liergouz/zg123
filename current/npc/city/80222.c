
// �Զ����ɣ�/make/npc/make8020

#include <npc.h>
#include <ansi.h>
#include <task.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 6011; }
void do_welcome( string arg );

// ������ʦ��ʶ��
int is_master() { return 1; }

// ������ʦ��ʶ��(���ͷ)
int is_basic_master() { return 2; }

int is_self_look() { return 1; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���������촦��
void create()
{
        set_name("�ܹ��÷�");
        set_real_name("�÷�1~29");
        set_city_name("�ܹ�");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
	set_skill(0640, 39);
        set_2( "good", ([
                "01" : "/item/product/64001",
                "02" : "/item/product/64002",
                "03" : "/item/product/64003",
                "04" : "/item/product/64004",
                "05" : "/item/product/64005",
                "06" : "/item/product/64006",
                "07" : "/item/product/64007",
                "08" : "/item/product/64008",
                "09" : "/item/product/64009",
                "10" : "/item/product/64010",
                "11" : "/item/product/64011",        
                "12" : "/item/product/64012",
                "13" : "/item/product/64013",
                "14" : "/item/product/64014",
                "15" : "/item/product/64015",      
                "16" : "/item/product/64016",
                "17" : "/item/product/64017",
                "18" : "/item/product/64018",
                "19" : "/item/product/64019",
                "20" : "/item/product/64020",
                "21" : "/item/product/64021",        
                "22" : "/item/product/64022",
                "23" : "/item/product/64023",
                "24" : "/item/product/64024",                                            
        ]) );	
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( who->get_legend(TASK_2_00,20) && !who->get_legend(TASK_2_00,21) && who->get_save("baifang_js_2") != 1)
		tmp = sprintf(ESC HIY "�ݷ�\ntalk %x# welcome.1\n",getoid(me));
	tmp += sprintf(ESC"ѧϰ����\nlearn ? %s\n", me->get_char_id());
	tmp += sprintf(ESC"����÷켼�ܵȼ�1-29�����䷽\nlist %s\n", me->get_char_id());
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    �����������ѧϰ�ں�����ѧ�������в÷켼�ܣ������߼����䷽��͵�ȥ�����ҹ��������ˡ�\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    �����������ѧϰ�ں�����ѧ�������в÷켼�ܣ������߼����䷽��͵�ȥ�����ҹ��������ˡ�\n",get_name()));
	
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 1 ); }
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_legend(TASK_2_00,20) && !who->get_legend(TASK_2_00,21) && who->get_save("baifang_js_2") != 1)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������İɡ���Ȼ�����������ݷ����ǣ�����Ե�����������ѧϰʲô���ܡ��ܹ�ѧϰ������ܳ��˾�ʳ�ǲ����Ƶ����⣬����ֻ��ѧϰ����Ŷ�������С�ĵ������������ܵĻ�������ȥ���깫����\n", me->get_name()));
			who->set_save("baifang_js_2",1);
			USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,20);
		}
		if ( who->get_save("baifang_js_0") == 1 && who->get_save("baifang_js_1") == 1 && who->get_save("baifang_js_2") == 1 && who->get_save("baifang_js_2") == 1 && who->get_save("baifang_js_3") == 1 && who->get_save("baifang_js_4") == 1 && who->get_save("baifang_js_5") == 1 && who->get_save("baifang_js_6") == 1 && who->get_save("baifang_js_7") == 1 )
		{
			who->set_legend(TASK_2_00,21);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,20,"���������ʦ��(���)" );
		}
        	break;
        }
}