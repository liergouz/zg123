
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1228; }

// ���������촦��
void create()
{
        set_name("��ս��");
        set_picid_1(6540);
        set_picid_2(6540);

        set_level(30);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 60);
        set("cp", 0);
        set("pp", 20);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ս��";
}
