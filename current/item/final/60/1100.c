
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 2069; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6058);
        set_picid_2(6058);

        set_level(100);
        set_value(7000);
        set_max_lasting(17899);
        set("ap", 0);
        set("dp", 230);
        set("cp", 0);
        set("pp", 158);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
