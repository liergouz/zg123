
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2129; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6600);
        set_picid_2(6600);

        set_level(45);
        set_value(8000);
        set_max_lasting(19899);
        set("ap", 0);
        set("dp", 76);
        set("cp", 0);
        set("pp", 39);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
