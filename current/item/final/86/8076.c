
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 1456; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(76);
        set_value(999);
        set_max_lasting(10099);
        set("ap", 92);
        set("dp", 0);
        set("cp", 144);
        set("pp", 93);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
