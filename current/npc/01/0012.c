
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5301; }

// ���������촦��
void create()
{
        set_name( "�󲮹�" );
        set_char_photoid(5303);
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));    
        setup();    
}


void do_look( object who )
{
        int status;
        string result;
        object me = this_object();
        result = sprintf("%s��\n    �١������ˣ���Ȼ�Ǹ���ѧϰ�ĺú��ӣ�����֪��Щʲô�أ�\n", me->get_name());
        status = who->get("dabogong");
        if ( (status & 1)==0)
                result += sprintf(ESC "�����˽���Ʒ�����֪ʶ��\ntalk %x# welcome.1\n",getoid(me) );
        if ( (status & 2)==0)
                result += sprintf(ESC "��������ʲô�õģ�\ntalk %x# welcome.4\n",getoid(me) );        
        result +=         ESC "ûʲô��·�����ѡ�\nCLOSE\n";
        send_user( who, "%c%c%s", ':', 2, result);        
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj;
//        object me;        
        string cmd1, result;
//        me = this_object();
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        status = who->get("dabogong");
        switch(flag)
        {
        case 1:
                cmd1 = sprintf("talk %x# welcome.2", getoid(me));
                result = sprintf("%s��\n    �ڷ��䣬���������������������Ѫ�ģ����㿴���������Ͻ��Ǹ���ɫ��Ѫ������Ѫ����ʱ��������Ҽ�������һ�¾Ϳ������Ͼ�ʹ�ò��������Ѫ�ˡ����⣬�����������������������ҷ����Ϸ����Ŀ�����У��Ժ�ֻ�е��Ԥ��Ŀ�ݼ�����ֱ��ʹ�á��о�ɢ�ͻ������������ͬ�������о�ɢ������Ѫ����û�л������Ŷ��\n"
                        ESC "����\n%s\n"
                        ESC "�ر�\nCLOSE\n", me->get_name(), cmd1 );
                send_user( who, "%c%c%w%s", ':', 4, 5301, result );        
                break;
        case 2:
                cmd1 = sprintf("talk %x# welcome.3", getoid(me));
                result = sprintf("%s��\n    װ���أ������������Լ��ģ��ְ�ɫ����ɫ����ɫ���֣������ɵ͵��ߣ��߼�װ�������ܸ��õı����Լ�����������Ĺ�����ø�ǿ��װ�����÷���������һ��������Ҽ�������������װ�������ϡ���Ȼ��װ������������һ����������ҷ�����߿������ʹ�á�\n"
                        ESC "����\n%s\n"
                        ESC "�ر�\nCLOSE\n", me->get_name(), cmd1 );
                send_user( who, "%c%c%w%s", ':', 4, 5301, result );     
                break;        
        case 3:              
                result = sprintf("%s��\n    ͨ������������Ʒ��������ڵ��ϣ���ʱֻҪ���һ�µ��ϵ���Ʒ���ͻ��Զ���������ĵ��������ˣ��������ߵ�˵����������������ˣ��������������������ʣ������ȥ���ʱ������Ŷ��\n"
                        ESC "�ر�\nCLOSE\n", me->get_name() );
                send_user( who, "%c%c%w%s", ':', 4, 5301, result );    
                break;        
        case 4:      
                result = sprintf("%s��\n    �������ʵúã����̵����ÿɴ����������󴳵���������������ص���Ʒ������ʱ���õ���Ʒ������ռ�������ϵĵ������������ս����ʱ������������ã�������ʧ�ܴ�Ŷ�������кܶ�õ���Ʒ��û���񣬻�����Ҫ��ʹ�������������Ʒ���У�Ҫ����������ʧ���ҵ��̰�æ�;���û���ɲ������Դ�������һ���������ĵ���������Ӫ���Ѿ��鲼ȫ���£�Ϊ���������ṩ����ȫ���������а�ȫ���б��ϵķ���\n"
                        ESC "�ر�\nCLOSE\n", me->get_name() );
                send_user( who, "%c%c%w%s", ':', 4, 5301, result );    
                break;                                                                
        }
}
