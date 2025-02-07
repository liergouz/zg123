/****************************************/
/*************PVP��������Ա**************/
/****************************************/

#include <npc.h>
#include <ansi.h>
#include <effect.h>


inherit OFFICER;

mapping Map=([
		"����":({501, 256 ,159}),"С��":({502, 257, 156}),"���":({503, 65, 108}),"ѩ��ɽ�ص�":({530, 241, 83}),
		"�����ص�":({529, 243, 86}),"��ɽ�ص�":({528, 185, 47}),"��ɽ":({513, 154, 216}),"��ɽ��ԭ":({512, 177, 213}),
		"����ɽ":({511, 169, 222}),"������ԭ":({510, 167, 222}),"��ɽ�ص�":({527, 37, 125}),"�����ص�":({526, 238, 81}),
		"��ԭ�ص�":({525, 107, 81}),"��ɽ�ص�":({524, 37, 125}),"�Ͻ�":({517, 254, 160}),"��ũ":({516, 294, 124}),
		"�׾�":({515, 254, 157}),"����":({ 514, 231, 178}),"�ڽ�":({505, 259, 154}),"����":({ 504, 262, 155}),
		"ǧ��":({509, 201, 205}),"����":({508, 260, 154}),"����":({507, 55, 107}),"��ī":({506, 63, 103}),
		"����":({522, 260,91}),"�����":({520,171, 35}),"��ƽ��":({523, 220, 178}),"����":({521, 278, 140}),
		"�ϵ�":({532,256,160}),"ƽ��":({ 531, 165, 215}),"���":({519, 231, 179}),"����":({ 518, 84, 83}),
		]);

//��ȡNPC����
int get_char_picid()
{
	return 5109;
}

void do_welcome(string arg);

//�����ʼ��
void create()
{
	set_name("PVP��������Ա");
	set_2("talk",(["welcome":(:do_welcome:)]));
	setup();
}

//�Ի�����
void do_look(object who)
{
	string result;
	object me=this_object();
	
	result=sprintf(me->get_name()+":\n    ����ս����Ȥ�����ѣ��ҿ����ṩ����������������ظ��㣬ϲ����ս������ѡ��һ���ʺ�����������ؾ��鷢����ı����~��\n");
	result+=sprintf(ESC "���͵�45~50��PVP��ͼ\ntalk %x# welcome.1\n",getoid(me));
	result+=sprintf(ESC "���͵�55~60��PVP��ͼ\ntalk %x# welcome.2\n",getoid(me));
	result+=sprintf(ESC "���͵�65~70��PVP��ͼ\ntalk %x# welcome.3\n",getoid(me));
	result+=sprintf(ESC "���͵�75~80��PVP��ͼ\ntalk %x# welcome.4\n",getoid(me));
	result+=sprintf(ESC "���͵�85~90��PVP��ͼ\ntalk %x# welcome.5\n",getoid(me));
	result+=sprintf(ESC "���͵�95~100��PVP��ͼ\ntalk %x# welcome.6\n",getoid(me));
	result+=sprintf(ESC "���͵�105~110��PVP��ͼ\ntalk %x# welcome.7\n",getoid(me));
	result+=sprintf(ESC "�뿪");
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}

void do_welcome2(object me,string arg)
{
	int flag,z,x,y,level,*zxy;
	string *key,result,mapname;
	object who;
	
	who=this_player();
	who->set_time("talk",0);
	level=who->get_level();
	if(!arg) return; 
	key=explode(arg," ");
	flag=to_int(key[0]);
	switch(flag)
	{
		case 1:
			//if(!(level>44)&&!(level<51)) return;
			result=sprintf(me->get_name()+":\n    ��Ҫȥ45������50�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n");
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			result+=sprintf(ESC "С��\ntalk %x# welcome.10 С��\n",getoid(me));
			result+=sprintf(ESC "���\ntalk %x# welcome.10 ���\n",getoid(me));
			result+=sprintf(ESC "ѩ��ɽ�ص�\ntalk %x# welcome.10 ѩ��ɽ�ص�\n",getoid(me));
			result+=sprintf(ESC "�����ص�\ntalk %x# welcome.10 �����ص�\n",getoid(me));
			result+=sprintf(ESC "��ɽ�ص�\ntalk %x# welcome.10 ��ɽ�ص�\n",getoid(me));
			result+=sprintf(ESC "�뿪");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 2:
			//if(!(level>54)&&!(level<61)) return;
			result=sprintf(me->get_name()+":\n    ��Ҫȥ55������60�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n");
			result+=sprintf(ESC "��ɽ\ntalk %x# welcome.10 ��ɽ\n",getoid(me));
			result+=sprintf(ESC "��ɽ��ԭ\ntalk %x# welcome.10 ��ɽ��ԭ\n",getoid(me));
			result+=sprintf(ESC "����ɽ\ntalk %x# welcome.10 ����ɽ\n",getoid(me));
			result+=sprintf(ESC "������ԭ\ntalk %x# welcome.10 ������ԭ\n",getoid(me));
			
			result+=sprintf(ESC "�뿪");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 3:
			//if(!(level>64)&&!(level<71)) return;
			result=sprintf(me->get_name()+":\n    ��Ҫȥ65������70�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n");
			result+=sprintf(ESC "��ɽ�ص�\ntalk %x# welcome.10 ��ɽ�ص�\n",getoid(me));
			result+=sprintf(ESC "�����ص�\ntalk %x# welcome.10 �����ص�\n",getoid(me));
			result+=sprintf(ESC "��ԭ�ص�\ntalk %x# welcome.10 ��ԭ�ص�\n",getoid(me));
			result+=sprintf(ESC "��ɽ�ص�\ntalk %x# welcome.10 ��ɽ�ص�\n",getoid(me));
			result+=sprintf(ESC "�Ͻ�\ntalk %x# welcome.10 �Ͻ�\n",getoid(me));
			result+=sprintf(ESC "��ũ\ntalk %x# welcome.10 ��ũ\n",getoid(me));
			result+=sprintf(ESC "�뿪");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 4:
			//if(!(level>74)&&!(level<81)) return;
			result=sprintf(me->get_name()+":\n    ��Ҫȥ75������80�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n");
			result+=sprintf(ESC "�׾�\ntalk %x# welcome.10 �׾�\n",getoid(me));
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			result+=sprintf(ESC "�ڽ�\ntalk %x# welcome.10 �ڽ�\n",getoid(me));
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			result+=sprintf(ESC "�뿪");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 5:
			//if(!(level>84)&&!(level<91)) return;
			result=sprintf(me->get_name()+":\n    ��Ҫȥ85������90�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n");
			result+=sprintf(ESC "ǧ��\ntalk %x# welcome.10 ǧ��\n",getoid(me));
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			result+=sprintf(ESC "��ī\ntalk %x# welcome.10 ��ī\n",getoid(me));
			result+=sprintf(ESC "�뿪");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 6:
			//if(!(level>94)&&!(level<101)) return;
			result=sprintf(me->get_name()+":\n    ��Ҫȥ95������100�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n");
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			result+=sprintf(ESC "����� \ntalk %x# welcome.10 �����\n",getoid(me));
			result+=sprintf(ESC "��ƽ��\ntalk %x# welcome.10 ��ƽ��\n",getoid(me));
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			
			result+=sprintf(ESC "�뿪");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 7:
			//if(!(level>104)&&!(level<111)) return;
			result=sprintf(me->get_name()+":\n    ��Ҫȥ105������110�����µ�������ͼ������ѡ��ɣ���Alt+M���Բ鿴��Щ��ͼ����Ĺ�������Ŷ��\n");
			result+=sprintf(ESC "�ϵ�\ntalk %x# welcome.10 �ϵ�\n",getoid(me));
			result+=sprintf(ESC "ƽ��\ntalk %x# welcome.10 ƽ��\n",getoid(me));
			result+=sprintf(ESC "���\ntalk %x# welcome.10 ���\n",getoid(me));
			result+=sprintf(ESC "����\ntalk %x# welcome.10 ����\n",getoid(me));
			
			result+=sprintf(ESC "�뿪");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 10:
			if(!sscanf(arg,"%d %s",flag,mapname)==2) return;
			zxy=Map[mapname];
			if(!zxy) return;
			z=zxy[0];x=zxy[1];y=zxy[2];
			__FILE__->send_ok(who,z,x,y);
			break;
			
	}
}

//���Դ���
void send_ok(object who,int z,int x,int y)
{
	int p;
	object me=this_object();
	p=x*1000+y;
	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "�����С���");
        who->set_2("travel.z",z);
	who->set_2("travel.p",p);
	set_effect(who, EFFECT_TRAVEL, 3);
//	me->add_to_scene(z,x-2,y-2);
}