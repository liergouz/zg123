
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 2035; }

// ���������촦��
void create()
{
        set_name("ӫ���");
        set_picid_1(6578);
        set_picid_2(6578);

        set_level(80);
        set_value(6000);
        set_max_lasting(15899);
        set("ap", 0);
        set("dp", 59);
        set("cp", 0);
        set("pp", 100);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ӫ���";
}
