
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1314; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(30);
        set_value(10000);
        set_max_lasting(6099);
        set("ap", 41);
        set("dp", 0);
        set("cp", 0);
        set("pp", 34);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
