
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 1362; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(60);
        set_value(20000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 0);
        set("cp", 125);
        set("pp", 78);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
