
// 自动生成：/make/npc/make8020

#include <npc.h>
#include <ansi.h>
#include <task.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5405; }

void do_welcome(string arg);

// 函数：师父识别
int is_master() { return 1; }

// 函数：师父识别(武教头)
int is_basic_master() { return 2; }

int is_self_look() { return 1; }

// 函数：小贩识别
int is_seller() { return 1; }

// 函数：构造处理
void create()
{
        set_name("周国石刻师");
        set_real_name("石刻1~30");
        set_city_name("周国");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
	set_skill(0650, 39);
        set_2( "good", ([
                "01" : "/item/product/65001",
                "02" : "/item/product/65002",
                "03" : "/item/product/65003",
                "04" : "/item/product/65004",
                "05" : "/item/product/65005",
                "06" : "/item/product/65006",
                "07" : "/item/product/65007",
                "08" : "/item/product/65008",
                "09" : "/item/product/65009",
                "10" : "/item/product/65010",
                "11" : "/item/product/65011",        
                "12" : "/item/product/65012",
                "13" : "/item/product/65013",
                "14" : "/item/product/65014",
                "15" : "/item/product/65015",      
                "16" : "/item/product/65016",
                "17" : "/item/product/65017",
                "18" : "/item/product/65018",
                "19" : "/item/product/65019",
                "20" : "/item/product/65020",
                "21" : "/item/product/65021",                                                
        ]) );	
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( who->get_legend(TASK_2_00,20) && !who->get_legend(TASK_2_00,21) && who->get_save("baifang_js_6") != 1)
		tmp = sprintf(ESC HIY "拜访\ntalk %x# welcome.1\n",getoid(me));
	tmp += sprintf(ESC"学习技能\nlearn ? %s\n", me->get_char_id());
	tmp += sprintf(ESC"购买石刻技能等级1-30级的配方\nlist %s\n", me->get_char_id());
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,40000,sprintf( "%s：\n    在我这你可以学习在楚国能学到的所有石刻技能，不过高级的配方你就得去楚国找工匠购买了。\n",get_name(),getoid(me)) +
		tmp +
		ESC"离开");
	else
		send_user(who,"%c%c%w%s",':',3,40000,sprintf( "%s：\n    在我这你可以学习在楚国能学到的所有石刻技能，不过高级的配方你就得去楚国找工匠购买了。\n",get_name()));
	
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
		if ( who->get_legend(TASK_2_00,20) && !who->get_legend(TASK_2_00,21) && who->get_save("baifang_js_6") != 1)
		{
			send_user(who, "%c%c%w%s", ':', 3, 40000, sprintf("%s:\n    你是新来的吧。既然大王派你来拜访我们，你可以到处看看，想学习什么技能。能够学习的生活技能除了酒食是不限制的以外，其他只能学习两种哦。如果不小心点错想忘记生活技能的话，可以去找申公豹。\n", me->get_name()));
			who->set_save("baifang_js_6",1);
			USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,20);
		}
		if ( who->get_save("baifang_js_0") == 1 && who->get_save("baifang_js_1") == 1 && who->get_save("baifang_js_2") == 1 && who->get_save("baifang_js_2") == 1 && who->get_save("baifang_js_3") == 1 && who->get_save("baifang_js_4") == 1 && who->get_save("baifang_js_5") == 1 && who->get_save("baifang_js_6") == 1 && who->get_save("baifang_js_7") == 1 )
		{
			who->set_legend(TASK_2_00,21);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,20,"访问生活技能师傅(完成)" );
		}
        	break;
        }
}