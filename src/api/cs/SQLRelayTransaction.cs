// Copyright (c) 1999-2018 David Muse
// See the file COPYING for more information

using System;
using System.Data;

namespace SQLRClient
{
    public class SQLRelayTransaction : IDbTransaction
    {

        #region member variables

        private Boolean _open = false;

        #endregion


        #region constructors and destructors

        internal SQLRelayTransaction()
        {
            _open = true;
        }

        /** Releases all resources used by the SQLRelayTransaction. */
        ~SQLRelayTransaction()
        {
            Dispose(false);
        }

        private void Dispose(Boolean disposing)
        {
            if (disposing)
            {
                if (_open && Connection != null)
                {
                    Rollback();
                }
            }
        }

        /** Releases the unmanaged resources used by the SQLRelayTransaction. */
        void IDisposable.Dispose()
        {
            Dispose(true);
            System.GC.SuppressFinalize(this);
        }

        #endregion


        #region properties

        public IDbConnection Connection
        {
            get;
            set;
        }

        public IsolationLevel IsolationLevel
        {
            get
            {
                return IsolationLevel.Unspecified;
            }
        }

        #endregion


        #region public methods

        /** Commits the database transaction. */
        public void Commit()
        {
            validTransaction();
            ((SQLRelayConnection)Connection).SQLRConnection.commit();
            _open = false;
        }

        /** Rolls back the database transaction. */
        public void Rollback()
        {
            validTransaction();
            ((SQLRelayConnection)Connection).SQLRConnection.rollback();
            _open = false;
        }

        #endregion


        #region private methods

        private void validTransaction()
        {
            if (!_open)
            {
                throw new InvalidOperationException("Transaction must be open");
            }
            if (Connection == null)
            {
                throw new InvalidOperationException("Connection must be non-null");
            }
            if (Connection.State != ConnectionState.Open)
            {
                throw new InvalidOperationException("Connection must be open");
            }
        }

        #endregion
    }
}
