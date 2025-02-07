
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 6010; }

// ���������촦��
void create()
{
        object me = this_object();
        set_name( "��������" );
        NPC_EQUIP_D->init_figure( this_object(), GIRL, FEMALE, 15 );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));    
        setup();     
}

void do_look( object who )
{
        int status;
        object me = this_object();

        status = who->get_2("yaoji.status");
        if (status==0)
        {                
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    �벻������ô������ˣ������ðٺϲŸոո��������㡣\n    ��û�����ҽ����ء������������ӣ�ר�Ÿ����ƹ����ļ��������ʵ��Ҳû��ʲô�ر�Ķ������Խ��㡣������Ҫ���������˽������Ժ�����Ϸ�������ռ��鱨������ģ������������˶Ի���ѧ��ܶ��µĶ����������� NPC������������������ռ��鱨Ҳʮ����Ҫ�����ܴ����˽����֮ǰ���˽�����顣\n"
                        ESC "����\ntalk %x# welcome.1", me->get_name(), getoid(me) ) );        
                who->set_2("yaoji.status", 1);                        
        }                        
        else        
                do_welcome("1");     
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, status;
        object who;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    ��Ҫ�� NPC ��̸����ֻҪ����굥����Ҫ��̸�� NPC �Ϳ����ˡ���Ҫ��������ҽ�������Ҫ�õ���Ϸ���ṩ�����칦�ܡ�\n    ���У�Ϊ�˱������֮��Ľ������ܵ������˵ĸ��ţ���Ϸ��һ��������" HIR "�߸�����Ƶ��" NOR "���ֱ��ǣ�" HIR "��ǰ�����ڡ����ҡ����ɡ����ɡ����顢���ס�ҥ��" NOR "��\n"
                        ESC "����\ntalk %x# welcome.2\n"
                        ESC "�ر�\nCLOSE\n", me->get_name(), getoid(me) ) );
                who->set_2("yaoji.status", 1);
                break;
        case 2:
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    ��ǰƵ��Ϊ�����������Ƶ���������Ƶ��������˵�Ļ�ֻ��ͬһ����Ļ������ܽ��յ��������������Ƶ�����ر�֮������˵�������ݻ���˵���ߵ�ͷ����ʾ������\n    ����Ƶ����һ�������Ե�Ƶ������Ϸ�����е���Ҷ���ͨ�����Ƶ���������ԣ����ɵؽ�����\n"
                        ESC "����\ntalk %x# welcome.3\n"
                        ESC "�ر�\nCLOSE\n", me->get_name(), getoid(me) ) );
                break;     
        case 3:
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    ����Ƶ����ר��Ϊͬһ�����ҵ���Ҷ���ģ�ֻ����������ͬ����ң������������Ƶ���л�ͨ��Ϣ��\n    ����Ƶ��������Ƶ�������Ƶ���������ƣ����������÷�Χ�޶�����������ѡ�����Ƶ��ֻ�����ڰ����ڲ�������;��������Ƶ��������С�Ӷ�Ա֮����໥ͨѶ��\n"
                        ESC "����\ntalk %x# welcome.4\n"
                        ESC "�ر�\nCLOSE\n", me->get_name(), getoid(me) ) );
                break;            
        case 4:
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    ����Ƶ����ʵҲ�빫��Ƶ��һ��������Ϊ�˷�������Ǿ��̽��׶��ر��趨��Ƶ����\n    ҥ��Ƶ����һ���Ƚ������Ƶ��������������ҿ����������������ķ�ʽ������Ϣ��һ��������֯Ҳ�����������Ƶ��������Ϸ����������һ�д��¡�\n"
                        ESC "����\ntalk %x# welcome.5\n"
                        ESC "�ر�\nCLOSE\n", me->get_name(), getoid(me) ) );
                break;      
        case 5:
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    ����Ƶ���Ĺ��ô�����ˡ����š����������ʱ�����Ƶ���е���Ϣ̫����ᷳ�Ļ�����������Ƶ������Ĺ��ܣ���һЩ�������ӵ�Ƶ�������Ϳ����ˡ���ʱ���Ƶ��ȫ������������һ������ʱ�̸о������ǲ���ġ�\n"
                        ESC "����\ntalk %x# welcome.6\n"
                        ESC "�ر�\nCLOSE\n", me->get_name(), getoid(me) ) );
                break;                                                    
        case 6:
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    ��ס������˽�̸ʱ̬��һ��Ҫ����Ŷ��Ҫѧ����ø��ֱ�������Լ������顣û�о����Լ����κ�Ŭ�����⿿һζ���ʱ��ˣ�ͬ������õ�ʲô�ý���ġ�\n    �������������������������У�һ�����������㽻�ĵĺ��ѡ���Ҫ��ԥ��������Ӻ��ѹ��ܣ������ѵ�������ӵ��Լ��ĺ����ֲ��С������Ļ����Ժ��������Ƿָ����أ��������ú��ѹ��ܻ����ż�����ϵ��\n"
                        ESC "����\ntalk %x# welcome.7\n", me->get_name(), getoid(me) ) );                
                break;
        case 7:
                send_user( who, "%c%c%w%s", ':', 4, 6010,
                        sprintf("%s��\n    ��������������˵�Ļ��������ٺ�����˵����һ���ڷܵ���һ�㶼û������һ���õ��������Ŭ���ɡ��һ���Զף����һ·ƽ����\n"
                        ESC "�ر�\nCLOSE\n", me->get_name() ) );                
                break;                
        }
}