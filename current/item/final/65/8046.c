
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2337; }

// ���������촦��
void create()
{
        set_name("׷�編��");
        set_picid_1(6558);
        set_picid_2(6558);

        set_level(46);
        set_value(1000);
        set_max_lasting(15899);
        set("ap", 0);
        set("dp", 38);
        set("cp", 0);
        set("pp", 62);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "׷�編��";
}
