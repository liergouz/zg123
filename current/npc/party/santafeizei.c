#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
// ��������ȡ��������
int get_char_picid() { return 1290; }
// ���������촦��
void create()
{
        set_name("ʥ������");
        setup();
}

void do_look(object who)
{
	object me=this_object();
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ҹ����������˯�ߣ�����Ϊֻ����˯���ţ�ԭ��%s��Ҳ˯���Ű����ѵ��㻹�ڵ�ʥ�����˵����",me->get_name(),who->get_name()));
}



