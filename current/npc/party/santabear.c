#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
// ��������ȡ��������
int get_char_picid() { return 1289; }
// ���������촦��
void create()
{
        set_name("ʥ������");
        setup();
}

void do_look(object who)
{
	object me=this_object();
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �򡭴򡭴�١������ǵ�IC��IP��IQ��ͳͳ����������Ҫ����ʥ������Ͻ����ң�",me->get_name()));
}



