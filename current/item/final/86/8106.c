
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 1459; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8605);
        set_picid_2(8605);

        set_level(106);
        set_value(999);
        set_max_lasting(19099);
        set("ap", 137);
        set("dp", 0);
        set("cp", 213);
        set("pp", 138);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
