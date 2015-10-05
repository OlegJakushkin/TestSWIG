using LibraryNamespace;

namespace Tests {
    internal class CSharpAwithDestructor: A {
        public enum State {
            None,
            Created,
            Destroyed
        }

        public static State LastState { get; set; }

        public CSharpAwithDestructor() {
            LastState = State.Created;
        }

        public override string SayHello() {
            return "C# Hell!";
        }

        public override void Dispose() {
            LastState = State.Destroyed;
            base.Dispose();
        }

        ~CSharpAwithDestructor() {
            Dispose();
        }
    }
}