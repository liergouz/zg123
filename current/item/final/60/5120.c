
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2289; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6062);
        set_picid_2(6062);

        set_level(120);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 200);
        set("cp", 0);
        set("pp", 311);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
