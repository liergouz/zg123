// ���﹥��������ģ
#include <ansi.h>
#include <map.h>
#include <city.h>
#include <skill.h>

private static int War;                 // ս��״̬
private static int z;                 	// ս����ͼ
private static int grade;               // ���ɵȼ�

private static string orgname;           // ��������

private static object *dbComrade = ({ });       // ����

string get_org_name() {return orgname;}
string set_org_name(string name) {return orgname = name;}

// ���������촦��
void create()
{
        object me = this_object();

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // �������
        set_heart_loop(me, 20);    // ѭ��������������
        me->heart_beat();
        set_heart_beat(1);
        War = WAR_READY;
}

// ��������ȡս��״̬
int get_war() { return War; }

// ����������ս��״̬
int set_war( int flag ) { return War = flag; }

int get_z() { return z;}

int set_z(int i) {return z=i;}

int get_grade() { return grade;}

int set_grade(int i) {return grade=i;}// ��������������

void heart_beat() { }

private static int HeartSec = 0;        // ������ʱ

// ��������ȡ������ʱ
int get_heart_sec() { return HeartSec; }

// ����������������ʱ
int set_heart_sec( int point ) { return HeartSec = point; }

// ����������������ʱ
int add_heart_sec( int point ) { return set_heart_sec(HeartSec + point); }

// ��������ȡ������ʿ��
object *get_comrade_dbase() { dbComrade -= ({ 0 });  return copy(dbComrade); }

// ��������ȡ������ʿ��
int sizeof_comrade_dbase() { dbComrade -= ({ 0 });  return sizeof(dbComrade); }

// ���������ӹ�����ʿ��
void add_comrade( object npc ) { dbComrade = dbComrade + ({ npc }) - ({ 0 }); }

// ������ɾ��������ʿ��
void sub_comrade( object npc ) { dbComrade -= ({ npc, 0 }); }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object map, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ2�봦��
{
        int sec = map->add_heart_sec(2);
        int time, count, value, i, j, p, x, y, z, color;
        string name, *attrib, *attrib2;
        object npc, orgnpc;
        name = map->get_org_name();
        orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
        if (!orgnpc)
        	return;
        if (sec<60) return;
        // ��9���ӹ���

        if (sec==60)
        {
        	FAMILY_D->org_channel( name, 0, HIR "�������ܵ�а��������Ϯ�������а��ھ���ص����ɣ����������ܹܡ�" );
        	FAMILY_D->org_channel( name, 0, HIR "��һ���Ĺ��ｫ��60���ʼ����������" );
        	return;
        }
        // ˢ41������
        	// �Ƿ�ȫ������ɾ�
        if (map->sizeof_comrade_dbase()>=3000 )
        {
        	CHAT_D->rumor_channel( 0, sprintf(HIR "��˵%s�ܵ��˹�������ҹ��򣬰�����ʩ�ܵ������𺦡�" , name));
        	orgnpc->add_train(-2);
        	orgnpc->add_stable(-300);
        	orgnpc->add_favour(-100);
        	orgnpc->set_gradewartime(0);
        	orgnpc->set_wardamage(0);
        	orgnpc->save();
        	FAMILY_D->org_channel( name, 0, HIR "��Ϊ�����Ĺ����Ѿ������˱����ɿ��Գ��ܵ�����300ֻ���˴����񳹵�ʧ���ˡ�" );
        	FAMILY_D->org_channel( name, 0, HIR "������Ϊ�ܵ��������Ϯ��������ʩ�ܵ����������ˡ�����������ģʧ�ܣ����ɰ������½�300�㣬�������½�100�㣬ѵ�����½�2�㡣" );
        	map->before_destruct();
        	destruct(map);
        	return;
        }
        // ��Ϊ���﹥������100��ս����ʧ�����м��
        if (orgnpc->get_gradewartime()==0)
        {
        	map->before_destruct();
        	destruct(map);
        	return;        	
        }
        if (sec<5) return;
        sec -= 5;
        if (sec<=5*5+5)
        {
        	time = sec / 5;	// �ڼ�������
        	count = (sec % 5)/2;
        	time ++;
        	attrib = "/quest/upgrade"->get_npc_attrib(map->get_grade(), sprintf("%d", time));
        	if (attrib==0) return;
        	value = to_int(attrib[6]);
        	if (value<16)
        	{
        		if (count>0) return;
        	}
        	else
        	{
        		if (count >= value/6) return;
        		value = value/16;
        	}
        	if (count==0)
        	{
        		FAMILY_D->org_channel( name, 0, HIR "�������ܵ�а��������Ϯ�������а��ھ���ص����ɣ����������ܹܡ�" );
        		FAMILY_D->org_channel( name, 0, sprintf(HIR "��%d���Ĺ��￪ʼ����������" , time));
        		if (time==1)
        			CHAT_D->rumor_channel( 0, sprintf(HIR "��˵%s�ļ�԰���ܵ������Ϯ����" , name));
        		else
        			FAMILY_D->org_channel( name, 0, sprintf(HIR "����%dֻ�����ڷ���������" , map->sizeof_comrade_dbase()));
        	}
        	value = value/3;
//log_file("test.dat", sprintf("%s sec=%d time=%d, count=%d attrib=%s value=%d npc=%d\n", short_time(), sec, time, count, attrib[6], value, map->sizeof_comrade_dbase() ));
        	z = map->get_z();
		for (i=0;i<3;i++)
		{
			p = get_jumpin(z, i+2);
                        x = ( p % 1000000 ) / 1000;
                        y = p % 1000;
			for (j=0;j<value;j++)
			{
				p = get_valid_xy( z, x + random(5), y + random(5), IS_CHAR_BLOCK );
				if (p)
				{
		                        x = ( p % 1000000 ) / 1000;
		                        y = p % 1000;
				}
				switch(attrib[5])
				{
				case "����":
				case "����":
					npc = new ("/npc/war/0100");
					break;
				case "����":
					npc = new ("/npc/war/0101");
					break;			
				default:
					npc = new ("/npc/war/0102");
					break;					
				}
				npc->set_name("���ɵ��ҷ���");
				npc->set_level(to_int(attrib[4]));
				npc->set_char_picid(to_int(attrib[0]));
				if (attrib[1]=="��") color = 0;
				else sscanf(attrib[1], "%x", color);
				npc->set_head_color(color);
				attrib2 = ({attrib[2], attrib[3], attrib[5] });
				"/sys/npc/energy"->init_npc(npc, npc->get_level(), attrib2);
				npc->add_to_scene(z, x, y, 6);
				map->add_comrade(npc);
			}
		}
        }
        else
        {
        	// �Ƿ�ȫ������ɾ�
        	if (map->sizeof_comrade_dbase()==0)
        	{
        		CHAT_D->rumor_channel( 0, sprintf(HIR "��˵%s�ɹ������˹������Ϯ�������˼�԰��" , name));
        		orgnpc->set_gradetime(time()+1*10);
        		orgnpc->add_train(-1);
        		orgnpc->add_stable(3000);
        		orgnpc->add_favour(1500);
        		orgnpc->set_gradewartime(0);
        		orgnpc->set_wardamage(0);
        		orgnpc->save();
        		FAMILY_D->org_channel( name, 0, HIR "�ڱ���ȫ���Ա��ͬ��Э��֮�£����ڻ����˹���Ĺ��������ɰ���������300�㣬����������150�㣬ѵ�����½�1�㡣��24Сʱ֮����ɵĹ�ģ�������һ����" );
	        	map->before_destruct();
	        	destruct(map);
        	}
        }
}

// ����������֮ǰ����
void before_destruct()
{
        object map, *char, npc;
        int i, size;

        map = this_object();

        if( arrayp( char = map->get_comrade_dbase() ) )
        {
                for( i = 0, size = sizeof(char); i < size; i ++ ) if( objectp( npc = char[i] ) )
                {
                        npc->remove_from_scene();
                        destruct(npc);
                }
        }
}