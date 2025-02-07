#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit OFFICER;

mapping maps = ([
	101:	([ "name" : 	"�����ǣ�",
		   "locate" :	({ 061,208,133, }),
		]),		   
	102:	([ "name" : 	"�����ǣ�",
		   "locate" :	({ 062,43,40, }),
		]),		   
	103:	([ "name" : 	"�����ǣ�",
		   "locate" :	({ 063,196,151, }),
		]),		   
	104:	([ "name" : 	"��ӹ��",
		   "locate" :	({ 284,252,198, }),
		]),		   
	105:	([ "name" : 	"��ɽ",
		   "locate" :	({ 283,208,28, }),
		]),		   
	106:	([ "name" : 	"�һ�Դ",
		   "locate" :	({ 282,185,127, }),
		]),		   
	107:	([ "name" : 	"������",
		   "locate" :	({ 281,29,150, }),
		]),		   

	201:	([ "name" : 	"����ɽ",
		   "locate" :	({ 081,244,154, }),
		]),		   
	202:	([ "name" : 	"�仪ɽ",
		   "locate" :	({ 082,200,80, }),
		]),		   
	203:	([ "name" : 	"���ȹ�",
		   "locate" :	({ 251,227,34, }),
		]),		   

	301:	([ "name" : 	"�޶��ӣ�",
		   "locate" :	({ 042,337,218, }),
		]),		   
	302:	([ "name" : 	"�޶��ӣ�",
		   "locate" :	({ 043,192,169, }),
		]),		   
	303:	([ "name" : 	"�޶�����",
		   "locate" :	({ 041,89,128, }),
		]),		   
	304:	([ "name" : 	"����",
		   "locate" :	({ 021,176,54, }),
		]),		   
	305:	([ "name" : 	"�����",
		   "locate" :	({ 141,136,67, }),
		]),		   
	306:	([ "name" : 	"����ׯ",
		   "locate" :	({ 142,100,56, }),
		]),		   
	307:	([ "name" : 	"��̤��",
		   "locate" :	({ 211,159,141, }),
		]),		   

	401:	([ "name" : 	"���ι�",
		   "locate" :	({ 089,85,59 }),
		]),		   
	402:	([ "name" : 	"ݽ��",
		   "locate" :	({ 181,226,48, }),
		]),		   
	403:	([ "name" : 	"��¹",
		   "locate" :	({ 131,64,63, }),
		]),		   
	404:	([ "name" : 	"��¹",
		   "locate" :	({ 271,199,183, }),
		]),		   
	405:	([ "name" : 	"��ˮ",
		   "locate" :	({ 272,113,180, }),
		]),		   
	406:	([ "name" : 	"����",
		   "locate" :	({ 242,133,40, }),
		]),		   
	407:	([ "name" : 	"��Ұ",
		   "locate" :	({ 241,138,43, }),
		]),		   
	408:	([ "name" : 	"̫��ɽ",
		   "locate" :	({ 132,83,35, }),
		]),		   
	409:	([ "name" : 	"����",
		   "locate" :	({ 182,134,32, }),
		]),		   
	410:	([ "name" : 	"ƽԭ",
		   "locate" :	({ 243,120,51, }),
		]),		   
	411:	([ "name" : 	"���Ź�",
		   "locate" :	({ 155,131,44, }),
		]),		   
	412:	([ "name" : 	"��ƽ",
		   "locate" :	({ 231,157,158, }),
		]),
		
	501:	([ "name" : 	"�����Ե",
		   "locate" :	({ 163,81,109, }),
		]),	
	502:	([ "name" : 	"����ش�",
		   "locate" :	({ 164,76,102, }),
		]),
	503:	([ "name" : 	"���ɽ��",
		   "locate" :	({ 261,101,42, }),
		]),
	504:	([ "name" : 	"���ɽ",
		   "locate" :	({ 262,91,35, }),
		]),
	505:	([ "name" : 	"��ɽ",
		   "locate" :	({ 263,53,46, }),
		]),
	506:	([ "name" : 	"۶����",
		   "locate" :	({ 264,48,117, }),
		]),
	507:	([ "name" : 	"���",
		   "locate" :	({ 265,79,47, }),
		]),
	508:	([ "name" : 	"̫��",
		   "locate" :	({ 266,81,75, }),
		]),
	509:	([ "name" : 	"̩ɽɽ��",
		   "locate" :	({ 112,149,178, }),
		]),
	510:	([ "name" : 	"̩ɽ",
		   "locate" :	({ 111,136,180, }),
		]),		
			
	601:	([ "name" : 	"�������",
		   "locate" :	({ 011,51,43, }),	
		]),		   
	602:	([ "name" : 	"������",
		   "locate" :	({ 012,108,52, }),
		]),		   
	603:	([ "name" : 	"������",
		   "locate" :	({ 013,51,121, }),
		]),		   
	604:	([ "name" : 	"������",
		   "locate" :	({ 014,70,77, }),
		]),		   
	605:	([ "name" : 	"������",
		   "locate" :	({ 015,130,29, }),
		]),		   
	606:	([ "name" : 	"֣������",
		   "locate" :	({ 151,76,24, }),
		]),		   
	607:	([ "name" : 	"֣������",
		   "locate" :	({ 152,47,40, }),
		]),		   
	608:	([ "name" : 	"֣������",
		   "locate" :	({ 153,31,48, }),	
		]),		   	   		   		   		   		   		   		   															
]);




// ��������ȡ��������
int get_char_picid() { return 6010; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�������ɴ���Ա");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who)
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, "");
}

void do_welcome( string arg )
{
        object who = this_object();
        __FILE__ ->do_welcome2(who, arg);
}

void do_welcome2( object who, string arg )
{
	int flag,id,i,size,p, x, y, z, *locate;
       	object me, robber;
       	string result;
       	mapping temp;
        me = this_player();
        flag = to_int(arg);
        me->set_time( "talk",  0);
        id = getoid(who);
        if (arg=="")
        {
        	if (me->get_level()>50)
        		result = sprintf("%s��\n    ���Ѿ�����50���˰ɡ����ڻ�����������ṩ�����ֵĴ��ͷ�ʽ�Ļ���ÿ�δ��Ͷ�Ҫ����500��Ŷ��\n", who->get_name() );
        	else
        		result = sprintf("%s��\n    ��ѽ�����������������ʶ�����Ҿ��Ǵ����������������ɴ���Ա�ˣ�������������Ϊ�������µ��ӵķ�չ��ί�������⿴��û���������������ģ�������ȥ���ʵȼ�����������ֻ��10����50��������Ŷ�����ջ���ɣ�\n", who->get_name() );
        	result += sprintf(ESC "���͵�10��14��������ͼ\ntalk %x# welcome.100\n", id );
        	result += sprintf(ESC "���͵�15��19��������ͼ\ntalk %x# welcome.200\n", id );
        	result += sprintf(ESC "���͵�20��24��������ͼ\ntalk %x# welcome.300\n", id );
        	result += sprintf(ESC "���͵�25��30��������ͼ\ntalk %x# welcome.400\n", id );
        	result += sprintf(ESC "���͵�31��40��������ͼ\ntalk %x# welcome.500\n", id );
        	result += sprintf(ESC "���͵�41��50��������ͼ\ntalk %x# welcome.600\n", id );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return ;
        }
        if (me->get_level()<10)
        {
        	result = sprintf("%s��\n    ����񻹺���Ŷ���������ִ帽�����һЩ���񣬴ﵽ10���������Ұɡ�\n", who->get_name() );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;
        }
	if( me->get_save_2("51cuanye.time")  )
	{
        	result = sprintf("%s��\n    ����ȡ�˽��ܼ��޴�Խ�����Ҿ��ݲ��Ӵ��ˡ�\n", who->get_name() );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;
	}
        if( present("ǮƱ", me, 1, MAX_CARRY) )
        {
        	result = sprintf("%s��\n    ��������ǮƱ���Ҿ��ݲ��Ӵ��ˡ�\n", who->get_name() );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;        	
        }
        if( present("������Ʒ", me, 1, MAX_CARRY) )
        {
        	result = sprintf("%s��\n    �������й�����Ʒ���Ҿ��ݲ��Ӵ��ˡ�\n", who->get_name() );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;   
        }
        if( objectp( robber = me->get_quest("escort.robber#") ) && robber->is_escort_robber() )    // Ѱ��������
        {
        	result = sprintf("%s��\n    �㸽���������ˣ��Ҿ��ݲ��Ӵ��ˡ�\n", who->get_name() );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;         	
        }        
        switch(flag)
        {
        case 100:
        	result = sprintf("%s��\n    ��Ҫȥ10������15�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n", who->get_name() );
        	for (i=0;i<7;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[101+i]["name"], id, 101+i );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;
        case 200:
        	result = sprintf("%s��\n    ��Ҫȥ15������20�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n", who->get_name() );
        	for (i=0;i<3;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[201+i]["name"], id, 201+i );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;        	
        case 300:
        	result = sprintf("%s��\n    ��Ҫȥ20������25�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n", who->get_name() );
        	for (i=0;i<7;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[301+i]["name"], id, 301+i );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;           
        case 400:
        	result = sprintf("%s��\n    ��Ҫȥ25������30�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n", who->get_name() );
        	for (i=0;i<12;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[401+i]["name"], id, 401+i );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;     
        case 500:
        	result = sprintf("%s��\n    ��Ҫȥ31������40�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n", who->get_name() );
        	for (i=0;i<10;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[501+i]["name"], id, 501+i );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;          
        case 600:
        	result = sprintf("%s��\n    ��Ҫȥ41������50�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n", who->get_name() );
        	for (i=0;i<8;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[601+i]["name"], id, 601+i );
        	result += ESC"�뿪\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;           		
        default:     	        	
        	temp = 	maps[flag];
        	if (!temp) return;
        	if (temp["name"]==0) return;
        	locate = temp["locate"];
        	if (sizeof(locate)!=3) return;
        	if (me->get_level()>50)
        	{
        		if (me->get_cash()<500)
        		{
        			result = sprintf("%s��\n    �����������ͷ��ô��\n", who->get_name() );
		        	result += ESC"�뿪\nCLOSE";
		        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return ;        			
        		}
        		me->add_cash(-500);
        	}
        	z = locate[0], x = locate[1], y = locate[2];
        	if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        	{
	                x = p / 1000;  y = p % 1000;	
	                me->add_to_scene( z, x, y, 3 );        		
        	}
        	break;
        }
}
