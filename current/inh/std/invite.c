#include <ansi.h>
#include <effect.h>

static mapping mpPic = (["������":40000,"éɽ":50105,"������":50103,"�һ�Դ":20000,"��ɽ":30000,"����ɽ":60000,"����":50000]);
// ���Լ���do_look����
int is_self_look() { return 1; }

// �������Ի�����
void do_look( object who )
{
        object me = this_object();
        __FILE__->do_look2(me,  who);
}

void do_look2( object me, object who )
{
        string name = me->get_fam_name();
        int pic;
        string result;
        if (!name) return;
        pic = mpPic[name];
        if ((me->get_char_picid()%2)==0) pic += 100;
        send_user( who, "%c%c%w%s", ':', 3, pic,
                sprintf("������ļԱ��\n    %s\n"
                ESC "ǰ��%s\ntalk %x# welcome.1\n"
                ESC "�ر�\nCLOSE\n", "/quest/word"->get_family_word(name), name, getoid(me) ) );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, p2, z, x, y, i, *locate, pic;
        object who, obj, item, item2;
        string cmd1, cmd2, cmd3, cmd4, cmd5, result, name;
        mixed mxTime;
	name = me->get_fam_name();
        who = this_player();
        flag = to_int(arg);
        pic = mpPic[name];
        if ((me->get_char_picid()%2)==0) pic += 100;        
        who->set_time( "talk",  0);
        p = 0;
        switch(flag)
        {
        case 1:
                if (who->get_level()<10)
                {
                        result = sprintf("%s��\n    ����Ŀǰ����Ϊ������ǰ�����Ű�ʦ������������Щ��������10���������Ұɣ�\n", me->get_name() );
                        send_user( who, "%c%c%w%s", ':', 3, pic, result );
                        return;
                }
                if( get_effect(who, EFFECT_TRAVEL) )
                {
                        send_user( who, "%c%s", '!', "���Ѿ��ڴ����С�" );
                        return;
                }
                if( present("������Ʒ", who, 1, MAX_CARRY*4) )
                {
                        send_user(who, "%c%s", '!', "���Ź�����Ʒ�������С�");
        //              write_user(me, ECHO "��������û���κ�Ч����");
                        return ;
                }
                locate = "/quest/word"->get_family_locate(me->get_fam_name());
                if (sizeof(locate)!=3) return;
                z = to_int(locate[0]);
                x = to_int(locate[1]);
                y = to_int(locate[2]);
                p2 = get_valid_xy( z, x + random(5), y + random(5), IS_CHAR_BLOCK );
                if (p2>0) p = p2;
                else
                p = to_int(locate[1])*1000+to_int(locate[2]);
                send_user(who, "%c%c%w%s", 0x5a, 0, 3, "�����С���");
                who->set_2("travel.z", z);
                who->set_2("travel.p", p);
                who->set_2("travel.money", 0);
                set_effect(who, EFFECT_TRAVEL, 3);
                break;
        }
}
