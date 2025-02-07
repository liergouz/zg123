#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 9968; }
void  restore_table(string file);
void do_welcome(string arg);
mapping question;
void create()
{	  
        set_2( "talk", ([
                "welcome"	:( : do_welcome :),
             ]));
        setup();
        restore_table("/quest/test_db.dat");  
        set_name( "凉拌仙" );
}
void  restore_table(string file)
{
	int result;
	if(!(result = restore_object(file,0)))
	{
		return;
	}
}
void validate_question(object player,string*physical)
{
	int index;
	for(index = 0; index < 4; index++)
	{
		if(!player->get_2(physical[index]))
		{
			return;
		}
	}
}
void response_question(object player, object npc, int flag,string*physical)
{
	int index,size;
	string father_choice,choice_question,test_type;
	__FILE__->validate_question(player,physical);
	test_type = player->get_2(physical[0]);
	father_choice = player->get_2(physical[1]);
	choice_question = player->get_2(physical[2]);
	if(!values(question[test_type][father_choice][choice_question]))
	{
		return;
	}
	size = sizeof(values(question[test_type][father_choice][choice_question]));
	if(!size)
	{
		return;
	}
	if(flag >= 11 && flag < 21)
	{
		if(flag < 11+size)
		{
			send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    "+values(question[test_type][father_choice][choice_question])[flag - 11]+"\n"+ESC "离开\n");//对应的子选项答案
		}
	}
}
void set_question_info(object player, int flag,string*physical)
{
	int size;
	string* key =({});
	string father_choice1,choice_question1,test_type;
	string* choice_content = ({});
	if(!question)
	{
		return;
	}
	size = sizeof(keys(question));
	if(!size)
	{
		return;
	}
	if(flag <= size)
	{
		player->set_2(physical[0],keys(question)[flag-1]);
	}
	else
	{
		return;
	}	
	test_type = keys(question)[flag-1];
	if(!test_type)
	{
		return;
	}
	key = keys(question[test_type]);
	if(!key)
	{
		return;
	}
	player->set_2(physical[1],key[random(sizeof(key))]);
	father_choice1 = player->get_2(physical[1]);
	if(!father_choice1)
	{
		return;
	}
	if(!keys(question[test_type][father_choice1])[0])
	{
		return;
	}
	player->set_2(physical[2],keys(question[test_type][father_choice1])[0]);
	choice_question1 = keys(question[test_type][father_choice1])[0];
	if(!choice_question1)
	{
		return;
	}
	choice_content = keys(question[test_type][father_choice1][choice_question1]);
	if(!choice_content)
	{
		return;
	}
	if(!sizeof(choice_content))
	{
		return;
	}
	player->set_2(physical[3],sizeof(choice_content));
}
void do_welcome(string arg)
{
	__FILE__->do_welcome2(this_object(),arg);
}
void do_welcome2(object npc,string arg)
{
	int flag,index,choice_size;
	string tmp1,dailogue,choice_question,father_choice1,test_type;
	string *physical = ({"physical.type","physical.choice","physical.question","physical.choice_size"});
	string* choice_content = ({});
	object player  = this_player();
	if(!arg)
	{
		return;
	}	
	flag = to_int(arg);
	switch(flag)
	{
	case 1:
	case 2:
        case 3:
		__FILE__->set_question_info(player,flag,physical);
		__FILE__->validate_question(player,physical);
		father_choice1 = player->get_2(physical[1]);
		tmp1 = sprintf(ESC"%s\ntalk %x# welcome.4\n",father_choice1,getoid(npc));//父选项
		tmp1 += ESC "离开\n";
	        send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),npc->get_name() + "：\n"+"    玉皇大帝是我哥，阎王老爷是我弟。\n" 
	        +tmp1); 
        	break;
        case 4:
		__FILE__->validate_question(player,physical);
		test_type = player->get_2(physical[0]);
		father_choice1 = player->get_2(physical[1]);
		choice_question = player->get_2(physical[2]);
		choice_size = player->get_2(physical[3]);

        	dailogue =npc->get_name()+"：\n"+"    "+choice_question+"\n";//获得父选项问题        			
        	for(index = 0; index < choice_size; index++)//choice_size所对应的size.
        	{
        		dailogue += sprintf(ESC"%s\ntalk %x# welcome.%d\n",keys(question[test_type][father_choice1][choice_question])[index],getoid(npc),11+index);//子选项。
        	}
        	dailogue += ESC "离开\n";
        	send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(), dailogue);   			
        	break;
        case 11..21://子选项所对应的答案
        	__FILE__->response_question(player,npc,flag,physical);   
        	break;     					
	}
}
void do_look(object player)
{
	string tmp1,tmp2,tmp3,test1,test2,test3;
	object npc = this_object();
	test1 = keys(question)[0];
	test2 = keys(question)[1];
	test3 = keys(question)[2];
	
	tmp1=sprintf(ESC"%s\ntalk %x# welcome.3\n",test3,getoid(npc));
	tmp2= sprintf(ESC"%s\ntalk %x# welcome.1\n",test1,getoid(npc));
	tmp3= sprintf(ESC"%s\ntalk %x# welcome.2\n",test2,getoid(npc));
	send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(), npc->get_name() + "：\n"+"    天灵灵，地灵灵，妖魔鬼怪全显形，这位客官，见你印堂发黑，定有事会发生，还是让本道为你算上一卦吧！问爱情还是问事业？\n" +
        tmp3 + tmp2+tmp1+
        ESC "离开\nCLOSE\n" );
}
